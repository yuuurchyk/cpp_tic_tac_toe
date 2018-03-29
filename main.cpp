#include <iostream>

#include "Player/Player.h"
#include "Field/Field.h"
#include "Game/Game.h"

int main(){
    std::istream &in_strm = std::cin;
    std::ostream &out_strm=  std::cout;

    Field::FieldInstance field;

    Player::HumanPlayer human(
        field,
        in_strm,
        out_strm,
        Tokens::Player::First,
        Player::get_human_player_name(in_strm,out_strm,Tokens::Player::First)
    );

    Player::MediumBot bot(
        field,
        in_strm,
        out_strm,
        Tokens::Player::Second,
        Player::get_medium_bot_player_name()
    );

    Game::GameInstance game(
        &field,
        &human,
        &bot
    );

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