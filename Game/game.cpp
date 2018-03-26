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

bool GameInstance::make_move(){
    if(field->get_free_cells_left() == 0)return false;
    if(field->is_winner() != Field::kEmpty)return false;

    index ^= 1;
    players[index]->make_move();

    return true;
}

std::string GameInstance::get_player_name() const{
    return players[index]->get_name();
}

char GameInstance::is_winner() const{
    return field->is_winner();
}

bool GameInstance::is_draw() const{
    return field->is_draw();
}