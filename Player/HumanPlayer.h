#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include <iostream>

#include "../Field/Field.h"
#include "../Tokens/Tokens.h"
#include "../Read/Read.h"

#include "AbstractPlayer.h"

namespace TicTacToe{
    class HumanPlayer : public AbstractPlayer{
    public:
        HumanPlayer(
            Field &field,
            std::istream &in_strm,
            std::ostream &out_strm,
            Player player,
            const std::string name
        );

        void make_move();

        ~HumanPlayer() = default;

    private:
        std::istream &in_strm;
        std::ostream &out_strm;
    };

    const std::string get_human_player_name(
        std::istream &in_strm,
        std::ostream &out_strm,
        Player player
    );
}

#endif