#ifndef MEDIUM_BOT_H_
#define MEDIUM_BOT_H_

#include <string>
#include <vector>

#include "../Field/Field.h"
#include "../Tokens/Tokens.h"
#include "../FieldTree/FieldTree.h"

#include "AbstractPlayer.h"

namespace TicTacToe{
    class MediumBot : public AbstractPlayer{
    public:
        MediumBot(
            Field &field,
            Player player,
            const std::string name
        );

        void make_move();
    };

    extern const std::vector<std::string> medium_bot_names;
    const std::string get_medium_bot_player_name();
}

#endif