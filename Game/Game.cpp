#include "Game.h"
#include "../Exceptions/CommonExceptions.h"

using namespace TicTacToe;

Game::Game(
    AbstractPlayer *playerX,
    AbstractPlayer *playerO,
    const Field &field
):
    playerX(playerX),
    playerO(playerO),
    field(field)
{
    if(playerX == nullptr || playerO == nullptr)
        throw NullPointerError();
}

bool Game::isEnd() const{
    return field.isDraw() || field.isWinner();
}

bool Game::isDraw() const{
    return field.isDraw();
}

bool Game::isWinner(Player *winner) const{
    return field.isWinner(winner);
}

std::string Game::getPlayerName(const Player &player) const{
    if(player == Player::X())
        return playerX->name;
    if(player == Player::O())
        return playerO->name;
    throw InternalLogicError();
}

void Game::makeMove(){
    if(currentPlayer == Player::X())
        playerX->makeMove();
    if(currentPlayer == Player::O())
        playerO->makeMove();
    currentPlayer.toggle();
}
