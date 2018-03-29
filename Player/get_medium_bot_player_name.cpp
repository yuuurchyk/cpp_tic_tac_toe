#include "Player.h"

const std::vector<std::string>
    Player::medium_bot_names = {
        "Ivan medium bot",
        "Helen medium bot",
        "George medium bot",
        "Luka medium bot"
    };

const std::string Player::get_medium_bot_player_name(){
    return Player::medium_bot_names[Common::get_random_number(0, Player::medium_bot_names.size() - 1)];
}