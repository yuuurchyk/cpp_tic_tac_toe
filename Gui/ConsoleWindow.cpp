#include "ConsoleWindow.h"
#include "Colors.h"
#include "../Exceptions/ConsoleWindowExceptions.h"

using namespace TicTacToe;

ConsoleWindow::ConsoleWindow(
    size_t x,
    size_t y,
    size_t width,
    size_t height,
    const std::string &header
):
    x(x),
    y(x),
    width(width),
    height(height),
    header(header),
    maxHeight(height - 2 * kPadding),
    maxWidth(width - 2 * kPadding)
{
    if(width < header.size())
        throw ConsoleWindowInitError();
    if(width <= 2 * kPadding)
        throw ConsoleWindowInitError();
    if(height <= 2 * kPadding)
        throw ConsoleWindowInitError();
    
    window = newwin(height, width, y, x);
    clear();
    this->refresh();
}

void ConsoleWindow::refresh(){
    wrefresh(window);
}

void ConsoleWindow::clear(){
    wclear(window);
    linesOccupied = 0;
    wattron(window, COLOR_PAIR(kConsoleBorderColor));
    box(window, 0, 0);
    mvwprintw(window, 0, 0, "%s", header.c_str());
    this->refresh();
}

void ConsoleWindow::moveCursor(){
    wmove(window, kPadding + linesOccupied, kPadding);
}

void ConsoleWindow::write(const Text &text){
    if(text.height() > maxHeight)
        throw ConsoleWriteError();
    if(text.maxWidth() > maxWidth)
        throw ConsoleWriteError();

    if(linesOccupied + text.height() > maxHeight)
        clear();

    for(const auto &line: text){
        short colorPair{0};
        switch(line.textType){
            case TextType::Regular:
                colorPair = kConsoleRegularColor;
                break;
            case TextType::Success:
                colorPair = kConsoleSuccessColor;
                break;
            case TextType::Error:
                colorPair = kConsoleErrorColor;
                break;
        }

        wattron(window, COLOR_PAIR(colorPair));
        moveCursor();
        wprintw(window, "%s", line.textStr.c_str());
        ++linesOccupied;
    }
    moveCursor();
    this->refresh();
}

std::string ConsoleWindow::inp(const Text &text){
    static constexpr size_t kBufferSize=1024;
    char buffer[kBufferSize];

    if(text.height() + 1 > maxHeight)
        throw ConsoleInpError();
    if(linesOccupied + text.height() + 1 > maxHeight)
        clear();
    write(text);

    wattron(window, COLOR_PAIR(kConsoleInpColor));
    wgetstr(window, buffer);
    buffer[kBufferSize - 1] = '\0';

    ++linesOccupied;

    return std::string(buffer);
}

ConsoleWindow::~ConsoleWindow(){
    delwin(window);
}