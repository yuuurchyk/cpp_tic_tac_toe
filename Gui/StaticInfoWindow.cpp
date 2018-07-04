#include "StaticInfoWindow.h"

using namespace TicTacToe;

StaticInfoWindow::StaticInfoWindow(
    size_t x,
    size_t y,
    size_t width,
    size_t height,
    const Text &text,
    const std::string header
):
    ConsoleWindow(x, y, width, height, header)
{
    write(text);
    this->refresh();
}