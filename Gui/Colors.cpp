#include <ncurses.h>

#include "Colors.h"

using namespace TicTacToe;

void TicTacToe::initColors(){
    init_pair(kConsoleBorderColor, COLOR_YELLOW, COLOR_BLACK);
    init_pair(kConsoleRegularColor, COLOR_WHITE, COLOR_BLACK);
    init_pair(kConsoleSuccessColor, COLOR_GREEN, COLOR_BLACK);
    init_pair(kConsoleErrorColor, COLOR_RED, COLOR_BLACK);
    init_pair(kConsoleInpColor, COLOR_CYAN, COLOR_BLACK);
    
    init_pair(kCellEmptyColor, COLOR_BLACK, COLOR_BLACK);
    init_pair(kCellXColor, COLOR_RED, COLOR_BLACK);
    init_pair(kCellOColor, COLOR_BLUE, COLOR_BLACK);

    init_pair(kFieldBorderColor, COLOR_YELLOW, COLOR_BLACK);
}