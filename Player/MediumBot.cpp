#include "MediumBot.h"

using namespace TicTacToe;

MediumBot::MediumBot(
    Field &field,
    Player player,
    const std::string name
):
    AbstractPlayer
    (
        field,
        player,
        name
    )
    {}

void MediumBot::make_move(){
    MediumBotFieldTree tree(
        field,
        player,
        player
    );

    field.set(tree.predict(), convert(player));
}

const std::vector<std::string>
    TicTacToe::medium_bot_names = {
        "Ivan medium bot",
        "Helen medium bot",
        "George medium bot",
        "Luka medium bot"
    };

const std::string TicTacToe::get_medium_bot_player_name(){
    return medium_bot_names[get_random_number(0, medium_bot_names.size() - 1)];
}