#include "Player.h"

const std::string Player::get_human_player_name(
    std::istream &in_strm,
    std::ostream &out_strm,
    char player
)
{
    static const std::string fail{"Name cannot contain whitespaces\n"};
    std::string prompt{"Player " + std::string(1, player) + ", please enter your name\n"};

    return Read::read_with_message<std::string>(
        in_strm,
        out_strm,
        prompt,
        fail
    );
}