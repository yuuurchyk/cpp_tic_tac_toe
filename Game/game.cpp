#include "Game.h"

using namespace Game;

GameInstance::GameInstance(
    Field::FieldInstance *field,
    Player::AbstractPlayer *first,
    Player::AbstractPlayer *second
):
    field(field)
{
    players.push_back(first);
    players.push_back(second);
}

bool GameInstance::move(){
    if(field->get_free_cells_left() == 0)return false;
    if(field->is_winner() != Field::kEmpty)return false;

    players[index]->make_move();
    index ^= 1;

    return true;
}