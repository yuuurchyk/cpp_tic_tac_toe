#ifndef MEDIUM_BOT_H_
#define MEDIUM_BOT_H_

#include "AbstractPlayer.h"
#include "../Tokens/Tokens.h"
#include "../Field/Field.h"

namespace TicTacToe{
    class MediumBot: public AbstractPlayer{
    public:
        MediumBot(Field &field, const Player &player);
        void makeMove();
        virtual ~MediumBot() = default;
    };
}

#endif