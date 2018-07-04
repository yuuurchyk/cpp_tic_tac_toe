#ifndef FIELD_TREE_EXCEPTIONS_H_
#define FIELD_TREE_EXCEPTIONS_H_

#include <exception>
#include "CommonExceptions.h"

namespace TicTacToe{
    class FieldTreeError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Something went wrong while operating with FieldTree";
        }
    };

    class FieldTreePredictionError: public FieldTreeError{
    public:
        const char * what() const noexcept{
            return "Cannot predict moves for the opponent";
        }  
    };

    class FieldTreeFullFieldPredictionError: public FieldTreeError{
    public:
        const char * what() const noexcept{
            return "Cannot predict for the full field";
        }
    };
}

#endif