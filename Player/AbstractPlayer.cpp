#include "AbstractPlayer.h"

using namespace TicTacToe;

AbstractPlayer::AbstractPlayer(
    Field &field,
    Player player,
    const std::string name
):
    player(player),
    field(field),
    name(name)
    {}

std::string AbstractPlayer::get_name() const{
    return name;
}

const Player& AbstractPlayer::get_player() const{
    return player;
}