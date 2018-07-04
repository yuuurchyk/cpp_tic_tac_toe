#include "FieldWindow.h"
#include "Colors.h"
#include "../Exceptions/CommonExceptions.h"

using namespace TicTacToe;

FieldWindow::FieldWindow(
    size_t x,
    size_t y,
    Field const *field
):
    x(x),
    y(y)
{
    if(field == nullptr)
        throw NullPointerError();
    this->field = field;
    window = newwin(kHeight, kWidth, y, x);

    wattron(window, COLOR_PAIR(kFieldBorderColor));
    box(window, 0, 0);
    mvwprintw(window, 0, 0, "Field");
    wrefresh(window);

    for(size_t i = 0; i < Field::kN; ++i)
        for(size_t j = 0; j < Field::kN; ++j)
            cells[i][j] = nullptr;
    
    for(size_t i = 0; i < Field::kN; ++i)
        for(size_t j = 0; j < Field::kN; ++j)
        {
            cells[i][j] = new CellWindow(
                x + kPadding + j * CellWindow::kWidth,
                y + kPadding + i * CellWindow::kHeight,
                field->at(i, j)
            );
            cells[i][j]->refresh();
        }
}

void FieldWindow::refresh(){
    wrefresh(window);
    for(size_t i = 0; i < Field::kN; ++i)
        for(size_t j = 0; j < Field::kN; ++j)
            cells[i][j]->refresh();
}

void FieldWindow::update(){
    for(size_t i = 0; i < Field::kN; ++i)
        for(size_t j = 0; j < Field::kN; ++j)
            if(field->at(i, j) != cells[i][j]->cell){
                auto x = cells[i][j]->x;
                auto y = cells[i][j]->y;
                delete cells[i][j];
                cells[i][j] = new CellWindow(x, y, field->at(i, j));
            }
    this->refresh();
}

void FieldWindow::update(Field const * newField){
    if(newField == nullptr)
        throw NullPointerError();
    field = newField;
    update();
}

FieldWindow::~FieldWindow(){
    delwin(window);
    for(size_t i = 0; i < Field::kN; ++i)
        for(size_t j = 0; j < Field::kN; ++j)
            delete cells[i][j];
}
