#include "Player.h"

const std::vector<std::string>
    Player::easy_bot_names = {
        "Ivan easy bot",
        "Helen easy bot",
        "George easy bot",
        "Luka easy bot"
    };

const std::string Player::get_easy_bot_player_name(){
    return Player::easy_bot_names[Common::get_random_number(0, Player::easy_bot_names.size() - 1)];
}