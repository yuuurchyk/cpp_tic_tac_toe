#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include "AbstractPlayer.h"
#include "../Controller/AbstractController.h"

namespace TicTacToe{
    class HumanPlayer: public AbstractPlayer{
    public:
        HumanPlayer(
            Field &field,
            const Player &player,
            AbstractController *controller
        );

        void makeMove();

        virtual ~HumanPlayer() = default;
    protected:
        AbstractController * controller{nullptr};
    };
}

#endif