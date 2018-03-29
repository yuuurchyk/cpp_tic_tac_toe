#include "Player.h"

using namespace Player;

AbstractPlayer::AbstractPlayer(
    Field::FieldInstance &field,
    std::istream &in_strm,
    std::ostream &out_strm,
    Tokens::Player player,
    const std::string name
):
    player(player),
    field(field),
    in_strm(in_strm),
    out_strm(out_strm),
    name(name)
    {}

std::string AbstractPlayer::get_name() const{
    return name;
}

const Tokens::Player& AbstractPlayer::get_player() const{
    return player;
}