#ifndef PLAYER_H_
#define PLAYER_H_

#include "AbstractPlayer.h"
#include "MediumBot.h"
#include "HumanPlayer.h"

#include "../Field/Field.h"
#include "../Tokens/Tokens.h"

namespace TicTacToe{
    AbstractPlayer *getPlayer(
        Field &field,
        const Player &player,
        AbstractController *controller
    );
}

#endif