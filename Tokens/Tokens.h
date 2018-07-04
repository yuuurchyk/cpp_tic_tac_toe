#ifndef TOKENS_H_
#define TOKENS_H_

#include <cstddef>
#include <ostream>

namespace TicTacToe{
    class Cell;
    class Player;

    class Cell{
    public:
        static constexpr size_t kBase{3};

        static Cell X();
        static Cell O();
        static Cell Empty();

        Cell();

        Cell(const Cell &rhs);
        bool operator==(const Cell &rhs) const;
        bool operator!=(const Cell &rhs) const;
        Cell& operator=(const Cell &rhs);

        explicit operator Player() const;
        explicit operator size_t() const;
        explicit operator char() const;
    private:
        static constexpr size_t
            kEmptyType{0},
            kXType{1},
            kOType{2};

        explicit Cell(size_t type);
        size_t type_;
    };

    std::ostream &operator<<(std::ostream &strm, const Cell &rhs);

    class Player{
    public:
        static constexpr size_t kBase{2};

        static Player X();
        static Player O();

        Player(const Player &rhs);
        bool operator==(const Player &rhs) const;
        bool operator!=(const Player &rhs) const;
        Player& operator=(const Player &rhs);

        Player& toggle();

        explicit operator Cell() const;
        explicit operator size_t() const;
        explicit operator char() const;
    private:
        static constexpr size_t
            kXType{0},
            kOType{1};

        explicit Player(size_t type);
        size_t type_;
    };

    std::ostream &operator<<(std::ostream &strm, const Player &rhs);
};

#endif