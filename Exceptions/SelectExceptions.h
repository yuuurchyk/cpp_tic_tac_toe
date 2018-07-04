#ifndef SELECT_EXCEPTIONS_
#define SELECT_EXCEPTIONS_

#include <exception>
#include "CommonExceptions.h"

namespace TicTacToe{
    class SelectInitError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Error occured while initializing Select";
        }
    };

    class OptionInitError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Error occured while initializing Option";
        }
    };
}

#endif