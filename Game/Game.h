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

namespace Game{
    class GameInstance{
    public:
        GameInstance(
            Field::FieldInstance *field,
            Player::AbstractPlayer *first,
            Player::AbstractPlayer *second
        );

        bool is_winner() const;
        bool is_draw() const;
        bool is_winner(const Tokens::Player &player) const;

        bool make_move();
        std::string get_player_name(const Tokens::Player &player) const;
    private:
        Field::FieldInstance *field;

        std::map<Tokens::Player, Player::AbstractPlayer*>
            players;
        
        Tokens::Player current_player;
    };
}

#endif