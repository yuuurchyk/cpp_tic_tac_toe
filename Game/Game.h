#ifndef GAME_H_
#define GAME_H_

#include <ostream>
#include <vector>
#include <map>
#include <utility>

#include "../Field/Field.h"
#include "../Player/Player.h"
#include "../Tokens/Tokens.h"
#include "../Exceptions/Exceptions.h"

namespace TicTacToe{
    class Game{
    public:
        Game(
            Field *field,
            AbstractPlayer *first,
            AbstractPlayer *second
        );

        bool is_winner() const;
        bool is_draw() const;
        bool is_winner(const Player &player) const;

        bool make_move();
        std::string get_player_name(const Player &player) const;
    private:
        Field *field;

        std::map<Player, AbstractPlayer*>
            players;
        
        Player current_player;
    };
}

#endif