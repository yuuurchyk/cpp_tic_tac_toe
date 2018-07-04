#include "HumanPlayer.h"
#include "../Text/Text.h"
#include "../Exceptions/CommonExceptions.h"

using namespace TicTacToe;

namespace{
    AbstractController *validateController(AbstractController *controller){
        if(controller == nullptr)
            throw NullPointerError();
        return controller;
    }
}

HumanPlayer::HumanPlayer(
    Field &field,
    const Player &player,
    AbstractController *controller
):
    AbstractPlayer(
        field,
        player,
        validateController(controller)->getPlayerName(
            Text{
                TextEntry(
                    TextType::Regular,
                    std::string("Player ") + static_cast<char>(player) + ", enter your name"
                )
            }
        )
    ),
    controller(controller)
{}

void HumanPlayer::makeMove(){
    auto cell = controller->getCoordinates(
        Text{
            TextEntry(
                TextType::Success,
                std::string("Player ") + name + ", enter you coordinates"
            )
        }
    );
    field_.set(cell.first, cell.second, player);
}
