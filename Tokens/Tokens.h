#ifndef TOKENS_H_
#define TOKENS_H_

#include <cstddef>
#include <ostream>

#include "../Exceptions/Exceptions.h"

namespace TicTacToe{
    enum class Cell{
        First, Second, Empty
    };
    enum class Player{
        First, Second
    };

    extern const size_t kHashBase;
    size_t getHash(const Cell &cell);
    char getChar(const Cell &cell);
    Player convert(const Cell &cell);
    std::ostream& operator<<(std::ostream &strm, const Cell &cell);

    Player opposite(const Player &player);
    char getChar(const Player &player);
    Cell convert(const Player &player);
    std::ostream& operator<<(std::ostream &strm, const Player &player);
}

#endif