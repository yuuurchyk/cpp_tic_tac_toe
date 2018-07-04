#include <ncurses.h>

#include "GuiController.h"
#include "Colors.h"
#include "../Exceptions/CommonExceptions.h"
#include "../Exceptions/ControllerExceptions.h"

using namespace TicTacToe;

const std::string TicTacToe::kGuiControllerToken{"--gui"};

bool GuiController::wasDestroyed{false};
GuiController *GuiController::controller{nullptr};

GuiController *GuiController::get(Field const * field){
    if(controller == nullptr){
        controller = new GuiController(field);
        return controller;
    }
    controller->update(field);
    return controller;
}

void GuiController::update(){
    AbstractController::update();
    staticInfoWindow->refresh();
    fieldWindow->update();
    consoleWindow->clear();
    consoleWindow->refresh();
}

void GuiController::update(Field const * field){
    AbstractController::update(field);
    update();
}

GuiController::~GuiController(){
    delete staticInfoWindow;
    delete fieldWindow;
    delete consoleWindow;
    endwin();
}

const size_t
    GuiController::kMinHeight{
        AbstractController::kInfoText.height() +
        2 * StaticInfoWindow::kPadding +
        FieldWindow::kHeight +
        10
    },
    GuiController::kMinWidth{30};

GuiController::GuiController(Field const * field):
    AbstractController(field)
{
    initscr();
    echo();
    cbreak();

    if(has_colors() == FALSE){
        endwin();
        throw GuiControllerTerminalColorError();       
    }

    start_color();
    initColors();

    int LINES, COLS;
    getmaxyx(stdscr, LINES, COLS);
    if(
        static_cast<size_t>(LINES) < kMinHeight ||
        static_cast<size_t>(COLS) < kMinWidth
    )
    {
        endwin();
        throw GuiControllerTerminalSizeError();
    }

    staticInfoWindow = new StaticInfoWindow(
        0,
        0,
        COLS,
        AbstractController::kInfoText.height() + 2 * StaticInfoWindow::kPadding,
        AbstractController::kInfoText
    );

    fieldWindow = new FieldWindow(
        0,
        staticInfoWindow->y + staticInfoWindow->height, 
        field
    );

    consoleWindow = new ConsoleWindow(
        0,
        fieldWindow->y + fieldWindow->kHeight,
        COLS,
        LINES - fieldWindow->kHeight - staticInfoWindow->height
    );

    update();
}

std::string GuiController::getRaw(const Text &text){
    return consoleWindow->inp(text);
}
