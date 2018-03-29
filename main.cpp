#include <iostream>

#include "Player/Player.h"
#include "Field/Field.h"
#include "Game/Game.h"
#include "PlayerFactory/PlayerFactory.h"

int main(){
    std::istream &in_strm = std::cin;
    std::ostream &out_strm=  std::cout;

    Field::FieldInstance field;

    Player::AbstractPlayer *first, *second;
    
    PlayerFactory::fill(in_strm, out_strm, field, &first, &second);

    Game::GameInstance game(&field, first, second);

    do out_strm << field << std::endl;
    while(game.make_move());

    if(field.is_draw())
        out_strm << "Draw :)" << std::endl;
    else if (field.is_winner(Tokens::Player::First))
        out_strm <<
            game.get_player_name(Tokens::Player::First) <<
            " won" << std::endl;
    else if(field.is_winner(Tokens::Player::Second))
        out_strm <<
            game.get_player_name(Tokens::Player::Second) <<
            " won" << std::endl;

    return 0;
}