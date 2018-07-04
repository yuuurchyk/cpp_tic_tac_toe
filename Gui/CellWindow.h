#ifndef CELL_WINDOW_H_
#define CELL_WINDOW_H_

#include <cstddef>
#include <array>
#include <ncurses.h>
#include "../Tokens/Tokens.h"

namespace TicTacToe{
    class CellWindow{
    public:
        static constexpr size_t
            kWidth{4},
            kHeight{4};
        
        const size_t x, y;
        const Cell cell;

        CellWindow(size_t x, size_t y, const Cell &cell);
        
        void refresh();

        ~CellWindow();
    private:
        static constexpr
            std::array<std::array<char, kWidth + 1>, kHeight>
                kEmptyText{
                    "    ",
                    "    ",
                    "    ",
                    "    "
                },
                kXText{
                    "\\  /",
                    " \\/ ",
                    " /\\ ",
                    "/  \\"
                },
                kOText{
                    " ## ",
                    "#  #",
                    "#  #",
                    " ## "
                };
        
        WINDOW *window;
    };
};

#endif