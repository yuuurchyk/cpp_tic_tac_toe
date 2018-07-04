#ifndef CONSOLE_WINDOW_EXCEPTIONS_H_
#define CONSOLE_WINDOW_EXCEPTIONS_H_

#include <exception>
#include "CommonExceptions.h"

namespace TicTacToe{
    class ConsoleWindowError: public TicTacToeError{
    public:
        const char *what() const noexcept{
            return "Something wrong while operating with console window";
        }
    };

    class ConsoleWindowInitError: public ConsoleWindowError{
    public:
        const char * what() const noexcept{
            return "Wrong sizes for console window";
        }
    };

    class ConsoleInpError: public ConsoleWindowError{
    public:
        const char * what() const noexcept{
            return "Input cannot fit into the console";
        }
    };

    class ConsoleWriteError: public ConsoleWindowError{
    public:
        const char * what() const noexcept{
            return "Text cannot fit into the console";   
        }
    };
}

#endif
