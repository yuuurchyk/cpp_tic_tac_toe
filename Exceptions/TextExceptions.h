#ifndef TEXT_EXCEPTIONS_H_
#define TEXT_EXCEPTIONS_H_

#include <exception>
#include "CommonExceptions.h"

namespace TicTacToe{
    class TextEntryError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Text cannot be empty string or consist of invalid characters";
        }
    };
}

#endif