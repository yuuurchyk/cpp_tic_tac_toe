#ifndef FIELD_WINDOW_H_
#define FIELD_WINDOW_H_

#include <array>
#include <ncurses.h>

#include "../Field/Field.h"
#include "CellWindow.h"

namespace TicTacToe{
    class FieldWindow{
    public:
        static constexpr size_t
            kPadding{1},
            kWidth{2 * kPadding + CellWindow::kWidth * Field::kN},
            kHeight{2 * kPadding + CellWindow::kHeight * Field::kN};
        
        FieldWindow(size_t x, size_t y, Field const * field);

        const size_t x, y;

        void update();
        void update(Field const * newField);
        void refresh();

        ~FieldWindow();
    private:
        Field const * field;
        std::array<std::array<CellWindow*, Field::kN>, Field::kN> cells;
        WINDOW *window;
    };
};

#endif