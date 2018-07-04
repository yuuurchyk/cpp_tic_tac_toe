#include "CellWindow.h"
#include "Colors.h"

using namespace TicTacToe;

constexpr
    std::array<std::array<char, CellWindow::kWidth + 1>, CellWindow::kHeight>
        CellWindow::kEmptyText,
        CellWindow::kXText,
        CellWindow::kOText;

CellWindow::CellWindow(
    size_t x,
    size_t y,
    const Cell &cell
):
    x(x),
    y(y),
    cell(cell),
    window(newwin(kHeight, kWidth, y, x))
{
    const auto &arr =
        (cell == Cell::Empty())?
            kEmptyText:
            (cell == Cell::X()? kXText: kOText);
    auto colorPair = 
        (cell == Cell::Empty())?
            kCellEmptyColor:
            (cell == Cell::X()? kCellXColor: kCellOColor);
    
    wattron(window, COLOR_PAIR(colorPair));
    for(size_t i = 0; i < kHeight; ++i)
        for(size_t j = 0; j < kWidth; ++j)
            mvwprintw(window, i, j, "%c", arr[i][j]);
    this->refresh();
}

void CellWindow::refresh(){
    wrefresh(window);
}

CellWindow::~CellWindow(){
    delwin(window);
}
