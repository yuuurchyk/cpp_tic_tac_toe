#include "Game.h"

using namespace TicTacToe;

Game::Game(
    Field *field,
    AbstractPlayer *first,
    AbstractPlayer *second
):
    field(field),
    current_player(Player::First)
{
    if(first == nullptr || second == nullptr)
        throw NoPlayerProvidedException();
    if(first->get_player() == second->get_player())
        throw SamePlayersException();
    if(field == nullptr)
        throw NoFieldProvidedException();

    players.insert(std::make_pair(Player::First, first));
    players.insert(std::make_pair(Player::Second, second));
}

bool Game::make_move(){
    if(field->is_draw() || field->is_winner())return false;

    players[current_player]->make_move();
    current_player = opposite(current_player);

    return true;
}

std::string Game::get_player_name(const Player &player) const{
    return players.at(player)->get_name();
}

bool Game::is_winner() const{
    return field->is_winner();
}

bool Game::is_winner(const Player &player) const{
    return field->is_winner(player);
}

bool Game::is_draw() const{
    return field->is_draw();
}