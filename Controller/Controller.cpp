#include "Controller.h"

using namespace TicTacToe;

AbstractController *TicTacToe::getController(
    Field const * field,
    const std::string &token
){
    if(token == kCmdControllerToken)
        return CmdController::get(field);
    if(token == kGuiControllerToken)
        return GuiController::get(field);
    return nullptr;
}