#include "Player.h"

#include "../Exceptions/CommonExceptions.h"
#include "../Select/Select.h"

using namespace TicTacToe;

AbstractPlayer *TicTacToe::getPlayer(
    Field &field,
    const Player &player,
    AbstractController *controller
){
    if(controller == nullptr)
        throw NullPointerError();
    
    Option humanPlayerOption("h", "human");
    Option mediumBotOption("m", "medium bot", "never loses");

    auto res = controller->select(
        std::string("Who will be player ") + static_cast<char>(player) + "?",
        Select{humanPlayerOption, mediumBotOption}
    );

    if(res == humanPlayerOption)
        return new HumanPlayer(field, player, controller);
    if(res == mediumBotOption)
        return new MediumBot(field, player);
    throw InternalLogicError();
}