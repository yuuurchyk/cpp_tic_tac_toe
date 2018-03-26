#ifndef GAME_H_
#define GAME_H_

#include <ostream>
#include <vector>

#include "../Field/Field.h"
#include "../Player/Player.h"

namespace Game{
    class GameInstance{
    public:
        GameInstance(
            Field::FieldInstance *field,
            Player::AbstractPlayer *first,
            Player::AbstractPlayer *second
        );

        char is_winner() const;
        bool is_draw() const;

        bool make_move();
        std::string get_player_name() const;
    private:
        Field::FieldInstance *field;
        std::vector<Player::AbstractPlayer*> players;

        int index{1};
    };
}

#endif