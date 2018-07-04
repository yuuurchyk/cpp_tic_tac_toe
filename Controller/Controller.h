#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>

#include "AbstractController.h"
#include "CmdController.h"
#include "GuiController.h"

namespace TicTacToe{
    AbstractController *getController(Field const * field, const std::string &token);
}

#endif