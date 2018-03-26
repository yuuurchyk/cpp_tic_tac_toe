#include "Player.h"

using namespace Player;

const std::vector<std::string>
    Player::silly_bot_names = {
        "Ivan Silly bot",
        "Max silly bot",
        "Helen silly bot",
        "Vasya silly bot"
    };

const std::string Player::get_silly_bot_player_name(){
    return silly_bot_names[Common::get_random_number(0, silly_bot_names.size() - 1)];
}