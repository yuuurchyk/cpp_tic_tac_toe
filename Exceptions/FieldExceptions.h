#ifndef FIELD_EXCEPTIONS_H_
#define FIELD_EXCEPTIONS_H_

#include <exception>
#include <cstddef>
#include <sstream>
#include <cstring>

#include "CommonExceptions.h"

namespace TicTacToe{
    class FieldError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Error while operating with field";
        };
    };

    class FieldCellOccupiedError: public FieldError{
    public:
        FieldCellOccupiedError(size_t i, size_t j)
        {
            std::stringstream strm;
            strm << "Cell " << i << " " << j << " is already occupied" << std::endl;
            strcpy(buffer, strm.str().c_str());
        }

        const char * what() const noexcept{
            return buffer;
        }
    private:
        static constexpr size_t kBufferSize{50};
        char buffer[kBufferSize];
    };

    class FieldOutOfBoundsError: public FieldError{
    public:
        const char * what() const noexcept{
            return"Coordinates of the cell are invalid";
        }
    };

    class FieldMoveOrderError: public FieldError{
    public:
        const char * what() const noexcept{
            return "Error in order of moves";
        }
    };

    class FieldDifferenceError: public FieldError{
    public:
        const char * what() const noexcept{
            return "Fields are identical";
        }
    };
};

#endif