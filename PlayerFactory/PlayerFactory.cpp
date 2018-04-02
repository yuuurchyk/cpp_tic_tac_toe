#include "PlayerFactory.h"

using namespace TicTacToe;
using std::string;

void TicTacToe::fillPlayer(
    std::istream &in_strm,
    std::ostream &out_strm,
    Field &field,
    const Player &player,
    AbstractPlayer **target
)
{
    string explanation =
        string("human - human player\n") +
        string("medium - medium bot (you will never win)\n");
    string fail = string("Wrong format");

    string prompt =
        string("Who will be the ") +
        (player == Player::First?
            string("first") :
            string("second")) +
        string(" player?\n");
    
    for(bool was = false;; was = true){
        string token = read_with_message<string>(
            in_strm,
            out_strm,
            was? "": prompt + explanation,
            fail
        );

        if(token == "human")
            *target = new HumanPlayer(
                field,
                in_strm,
                out_strm,
                player,
                get_human_player_name(in_strm, out_strm, player)
            );
        else if(token == "medium")
            *target = new MediumBot(
                field,
                player,
                get_medium_bot_player_name()
            );
        else{
            out_strm << "No valid token provided. Try again" << std::endl;
            continue;
        }

        break;
    }
}