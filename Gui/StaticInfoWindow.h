#ifndef STATIC_INFO_WINDOW_H_
#define STATIC_INFO_WINDOW_H_

#include <string>

#include "ConsoleWindow.h"
#include "../Text/Text.h"

namespace TicTacToe{
    class StaticInfoWindow: private ConsoleWindow{
    public:
        StaticInfoWindow(
            size_t x,
            size_t y,
            size_t width,
            size_t height,
            const Text &text,
            const std::string header="Info"
        );

        using ConsoleWindow::refresh;

        using ConsoleWindow::kPadding;
        
        using ConsoleWindow::x;
        using ConsoleWindow::y;
        using ConsoleWindow::width;
        using ConsoleWindow::height;
    };
}

#endif