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

    std::vector<Player::AbstractPlayer*> players;
    Field::FieldInstance field;

    std::string explanation = std::string(
"human - human player\n\
silly - silly bot\n\
easy - easy bot\n\
medium - medium bot\n"
    );
    std::string fail{"Wrong format"};

    for(int pnum = 0; pnum < 2; pnum++){
        std::string prompt{"Who will be the "};
        if(pnum == 0)prompt += "first";
        else prompt += "second";
        prompt += " player?\n";

        for(bool was=false;; was=true){
            std::string token = Read::read_with_message<std::string>(
                in_strm,
                out_strm,
                was? "": prompt + explanation,
                fail
            );

            if(token == "human")
                players.push_back(new Player::HumanPlayer(
                    field, in_strm, out_strm, pnum == 0,
                    Player::get_human_player_name(
                        in_strm,
                        out_strm,
                        pnum == 0? Field::kFirstPlayer : Field::kSecondPlayer
                    )
                ));
            else if(token == "silly")
                players.push_back(new Player::SillyBot(
                    field, in_strm, out_strm, pnum == 0,
                    Player::get_silly_bot_player_name()
                ));
            else if(token == "easy")
                players.push_back(new Player::EasyBot(
                    field, in_strm, out_strm, pnum == 0,
                    Player::get_easy_bot_player_name()
                ));
            else if(token == "medium")
                players.push_back(new Player::MediumBot(
                    field, in_strm, out_strm, pnum == 0,
                    Player::get_medium_bot_player_name()
                ));
            else{
                out_strm << "No valid token provided. Try again" << std::endl;
                continue;
            }

            break;
        }
    }

    Game::GameInstance game(&field, players[0], players[1]);

    do out_strm << field << std::endl;
    while(game.make_move());

    if(game.is_draw())
        out_strm << "Draw :)" << std::endl;
    else
        out_strm << game.get_player_name() << " has won!" << std::endl;
    

    for(int pnum = 0; pnum < 2; pnum++)
        delete(players[pnum]);
    
    return 0;
}