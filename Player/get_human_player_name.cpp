#include "Player.h"

const std::string Player::get_human_player_name(
    std::istream &in_strm,
    std::ostream &out_strm,
    Tokens::Player player
)
{
    static const std::string fail{"Name cannot contain whitespaces\n"};
    std::string prompt{
        "Player " +
        std::string(1, Tokens::getChar(player)) +
        ", please enter your name\n"
    };

    return Read::read_with_message<std::string>(
        in_strm,
        out_strm,
        prompt,
        fail
    );
}