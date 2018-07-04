#ifndef CONSOLE_WINDOW_H_
#define CONSOLE_WINDOW_H_

#include <string>
#include <cstddef>
#include <ncurses.h>

#include "../Text/Text.h"

namespace TicTacToe{
    class ConsoleWindow{
    public:
        static constexpr size_t kPadding{1};

        ConsoleWindow(
            size_t x,
            size_t y,
            size_t width,
            size_t height,
            const std::string &header="Console"
        );

        const size_t
            x,
            y,
            width,
            height;

        ~ConsoleWindow();

        std::string inp(const Text &text);
        void clear();
        void refresh();
        void write(const Text &text);
    private:
        void moveCursor();

        const std::string header;

        const size_t
            maxHeight,
            maxWidth;
        
        size_t linesOccupied{0};
        
        WINDOW *window{nullptr};
    };
}

#endif
