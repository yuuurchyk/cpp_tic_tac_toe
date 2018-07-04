#ifndef FIELD_H_
#define FIELD_H_

#include <ostream>
#include <cstddef>
#include <array>
#include <utility>

#include "../Tokens/Tokens.h"

namespace TicTacToe{
    class Field{
    public:
        static constexpr size_t kN{3};

        bool isDraw() const;
        bool isWinner(Player *winner=nullptr) const;

        const Cell& at(size_t i, size_t j) const;
        const Cell& operator()(size_t i, size_t j) const;
        void set(size_t i, size_t j, const Player &p);
        bool isOccupied(size_t i, size_t j) const;

        operator size_t() const;

        Player whooseMove() const;

        Field();
        Field(const Field &rhs);
        Field &operator=(const Field &rhs);
        bool operator==(const Field &rhs) const;

        std::pair<size_t, size_t> difference(const Field &rhs) const;
    private:
        inline static void validate(size_t i, size_t j);

        size_t freeCellsLeft_{kN * kN};
        std::array<std::array<Cell, kN>, kN> field_;
    };

    std::ostream &operator<<(std::ostream &strm, const Field &rhs);
}

#endif