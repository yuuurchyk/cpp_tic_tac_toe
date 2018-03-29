#ifndef TOKENS_H_
#define TOKENS_H_

#include <cstddef>
#include <ostream>

#include "../Exceptions/Exceptions.h"

namespace Tokens{
    enum class Cell{
        First, Second, Empty
    };

    extern const size_t kHashBase;

    size_t getHash(const Cell &cell);

    enum class Player{
        First, Second
    };

    Player opposite(const Player &player);

    char getChar(const Player &player);
    char getChar(const Cell &cell);

    Cell convert(const Player &player);
    Player convert(const Cell &cell);

    std::ostream& operator<<(std::ostream &strm, const Cell &cell);
    std::ostream& operator<<(std::ostream &strm, const Player &player);
}

#endif