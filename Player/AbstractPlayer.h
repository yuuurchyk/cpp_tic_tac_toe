#ifndef ABSTRACT_PLAYER_H_
#define ABSTRACT_PLAYER_H_

#include <string>
#include "../Tokens/Tokens.h"
#include "../Field/Field.h"

namespace TicTacToe{
    class AbstractPlayer{
    public:
        const Player player;
        const std::string name;

        AbstractPlayer(
            Field &field,
            const Player &player,
            const std::string &name
        );

        virtual void makeMove() = 0;
        virtual ~AbstractPlayer() = default;

    protected:
        Field &field_;
    };
};

#endif