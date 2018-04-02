#ifndef ABSTRACT_PLAYER_H_
#define ABSTRACT_PLAYER_H_

#include <string>

#include "../Field/Field.h"
#include "../Tokens/Tokens.h"

namespace TicTacToe{
    class AbstractPlayer{
    public:

        AbstractPlayer(
            Field &field,
            Player player,
            const std::string name
        );

        virtual void make_move() = 0;
        std::string get_name() const;
        const Player& get_player() const;
    
    protected:
        Field &field;

        const Player player;
        const std::string name;
    };
}

#endif