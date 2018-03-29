#ifndef PLAYER_FACTORY_H_
#define PLAYER_FACTORY_H_

#include <iostream>
#include <string>
#include <vector>

#include "../Read/Read.h"
#include "../Player/Player.h"
#include "../Field/Field.h"

namespace PlayerFactory{
    void fill(
        std::istream &in_strm,
        std::ostream &out_strm,
        Field::FieldInstance &field,
        Player::AbstractPlayer ** first,
        Player::AbstractPlayer ** second
    );
}

#endif