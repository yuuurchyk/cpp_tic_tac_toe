#include <iostream>

#include "Player/Player.h"
#include "Field/Field.h"
#include "Game/Game.h"
#include "PlayerFactory/PlayerFactory.h"

using namespace TicTacToe;
using std::cin;
using std::cout;
using std::endl;

int main(){

    Field field;

    AbstractPlayer *first, *second;
    
    fillPlayer(cin, cout, field, Player::First, &first);
    fillPlayer(cin, cout, field, Player::Second, &second);
    
    Game game(&field, first, second);

    do cout << field << endl;
    while(game.make_move());

    if(field.is_draw())
        cout << "Draw :)" << endl;
    else if (field.is_winner(Player::First))
        cout << game.get_player_name(Player::First) << " won" << endl;
    else if(field.is_winner(Player::Second))
        cout << game.get_player_name(Player::Second) << " won" << endl;

    delete first;
    delete second;

    return 0;
}