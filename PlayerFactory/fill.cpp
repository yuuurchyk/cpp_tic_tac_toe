#include "PlayerFactory.h"

void PlayerFactory::fill(
    std::istream &in_strm,
    std::ostream &out_strm,
    Field::FieldInstance &field,
    Player::AbstractPlayer ** first,
    Player::AbstractPlayer ** second
)
{
    std::string explanation = std::string(
"human - human player\n\
medium - medium bot (you will never win)\n"
    );
    std::string fail{"Wrong format"};

    std::vector<Player::AbstractPlayer **> players;
    players.push_back(first);
    players.push_back(second);
    *players[0] = NULL;
    *players[1] = NULL;

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
                *players[pnum] = new Player::HumanPlayer(
                    field,
                    in_strm,
                    out_strm,
                    pnum == 0?
                        Tokens::Player::First:
                        Tokens::Player::Second,
                    Player::get_human_player_name(
                        in_strm,
                        out_strm,
                        pnum == 0?
                            Tokens::Player::First:
                            Tokens::Player::Second
                    )
                );
            else if(token == "medium")
                *players[pnum] = new Player::MediumBot(
                    field,
                    in_strm,
                    out_strm,
                    pnum == 0?
                        Tokens::Player::First:
                        Tokens::Player::Second,
                    Player::get_medium_bot_player_name()
                );
            else{
                out_strm << "No valid token provided. Try again" << std::endl;
                continue;
            }

            break;
        }
    }
}