#include "AbstractPlayer.h"

using namespace TicTacToe;

AbstractPlayer::AbstractPlayer(
    Field &field,
    const Player &player,
    const std::string &name
):
    player(player),
    name(name),
    field_(field)
{}
