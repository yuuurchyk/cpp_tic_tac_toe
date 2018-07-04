#include <vector>
#include <string>
#include <cstdlib>

#include "MediumBot.h"
#include "../FieldTree/MediumBotFieldTree.h"

using namespace TicTacToe;

namespace{
    const std::vector<std::string>
        mediumBotNames{
            "Jim",
            "Bill",
            "Cortana",
            "Mike",
            "Helen"
        };
    std::string chooseMediumBotName(){
        return mediumBotNames.at(rand() % mediumBotNames.size());
    }
}

MediumBot::MediumBot(Field &field, const Player &player):
    AbstractPlayer(field, player, chooseMediumBotName())
{}

void MediumBot::makeMove(){
    auto res = MediumBotFieldTree(field_, player).predict();
    field_.set(res.first, res.second, player);
}
