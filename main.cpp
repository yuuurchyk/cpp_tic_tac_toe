#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Field/Field.h"
#include "Player/Player.h"
#include "Read/Read.h"
#include "Game/Game.h"

int main(){
    std::istream &in_strm = std::cin;
    std::ostream &out_strm = std::cout;

    Field::FieldInstance field;

    Player::HumanPlayer human{
        field,
        in_strm,
        out_strm,
        true,
        Player::get_human_player_name(in_strm, out_strm, Field::kFirstPlayer)
    };
    Player::EasyBot bot{
        field,
        in_strm,
        out_strm,
        false,
        Player::get_easy_bot_player_name()
    };

    Game::GameInstance game{
        &field,
        &human,
        &bot
    };

    do out_strm << field << std::endl;
    while(game.make_move());

    if(field.is_draw())
        out_strm << "Draw :)" << std::endl;
    else
        if(field.is_winner() == Field::kFirstPlayer)
            out_strm << "Winner: " << human.get_name() << std::endl;
        else
            out_strm << "Winner: " << bot.get_name() << std::endl;
    
    return 0;
}