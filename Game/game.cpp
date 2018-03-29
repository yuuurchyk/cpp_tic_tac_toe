#include "Game.h"

using namespace Game;
using Player::AbstractPlayer;
using Exceptions::SamePlayersException;
using Exceptions::NoPlayerProvidedException;
using Exceptions::NoFieldProvidedException;

GameInstance::GameInstance(
    Field::FieldInstance *field,
    AbstractPlayer *first,
    AbstractPlayer *second
):
    field(field),
    current_player(Tokens::Player::First)
{
    if(first == nullptr || second == nullptr)
        throw NoPlayerProvidedException();
    if(first->get_player() == second->get_player())
        throw SamePlayersException();
    if(field == nullptr)
        throw NoFieldProvidedException();

    players.insert(std::make_pair(Tokens::Player::First, first));
    players.insert(std::make_pair(Tokens::Player::Second, second));
}

bool GameInstance::make_move(){
    if(field->is_draw() || field->is_winner())return false;

    players[current_player]->make_move();
    current_player = Tokens::opposite(current_player);

    return true;
}

std::string GameInstance::get_player_name(const Tokens::Player &player) const{
    return players.at(player)->get_name();
}

bool GameInstance::is_winner() const{
    return field->is_winner();
}

bool GameInstance::is_winner(const Tokens::Player &player) const{
    return field->is_winner(player);
}

bool GameInstance::is_draw() const{
    return field->is_draw();
}