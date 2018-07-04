#ifndef TOKENS_EXCEPTIONS_H_
#define TOKENS_EXCEPTIONS_H_

#include <exception>
#include <cstddef>

#include "CommonExceptions.h"

namespace TicTacToe{
    class TokensError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Error while operating with tokens";
        }
    };

    class TokensConvertionError: public TokensError{
    public:
        const char * what() const noexcept{
            return "Cannot convert Empty Cell to Player";
        };
    };
};

#endif