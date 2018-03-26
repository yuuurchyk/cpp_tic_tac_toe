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

        bool move();

    private:
        Field::FieldInstance *field;
        std::vector<Player::AbstractPlayer*> players;

        int index{0};
    };
}

#endif