#ifndef COLORS_H_
#define COLORS_H_

namespace TicTacToe{
    constexpr short
        kConsoleBorderColor{1},
        kConsoleRegularColor{2},
        kConsoleSuccessColor{3},
        kConsoleErrorColor{4},
        kConsoleInpColor{5},
        kCellEmptyColor{6},
        kCellXColor{7},
        kCellOColor{8},
        kFieldBorderColor{9};
    
    void initColors();
}

#endif