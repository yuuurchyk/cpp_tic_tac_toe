#ifndef TOKENS_H_
#define TOKENS_H_

#include <cstddef>
#include <ostream>

#include "../Field/Field.h"
#include "../Exceptions/Exceptions.h"

namespace Tokens{
    enum class Cell{
        First, Second, Empty
    };

    extern const size_t kHashBase;

    char getChar(const Cell &cell);
    size_t getHash(const Cell &cell);

    enum class Player{
        First, Second
    };

    char getChar(const Player &player);

    Cell convert(const Player &player);
    Player convert(const Cell &cell);

    std::ostream& operator<<(std::ostream &strm, const Cell &cell);
    std::ostream& operator<<(std::ostream &strm, const Player &player);
}

#endif