#ifndef COMMON_EXCEPTIONS_H_
#define COMMON_EXCEPTIONS_H_

#include <exception>

namespace TicTacToe{
    class TicTacToeError: public std::exception{
    public:
        const char * what() const noexcept{
            return "Something went wrong during the program run";
        }
    };

    class InternalLogicError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Something in interal logic went wrong";
        }
    };

    class NullPointerError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Cannot dereference a null-pointer";
        }
    };
};

#endif