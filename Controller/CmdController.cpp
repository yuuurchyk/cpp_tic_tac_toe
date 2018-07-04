#include <iostream>

#include "CmdController.h"
#include "../Exceptions/ControllerExceptions.h"

using namespace TicTacToe;

const std::string TicTacToe::kCmdControllerToken{"--cmd"};

bool CmdController::wasDestroyed{false};
CmdController *CmdController::controller{nullptr};

CmdController *CmdController::get(Field const * field){
    if(controller == nullptr){
        if(wasDestroyed)
            throw ControllerGetError();
        controller = new CmdController(field);
        return controller;
    }
    controller->update(field);
    return controller;
}
CmdController::~CmdController(){
    wasDestroyed = true;
}

CmdController::CmdController(Field const * field):
    AbstractController(field)
{
    update();
}

void CmdController::clear(){
    std::cout << "\033[2J\033[1;1H";
}

void CmdController::update(){
    AbstractController::update();
    clear();
    write(kInfoText);
    std::cout << *field << std::endl;
}

void CmdController::update(Field const * newField){
    AbstractController::update(newField);
    update();
}

void CmdController::write(const Text &text){
    for(const auto &it: text){
        switch(it.textType){
            case TextType::Regular:
            case TextType::Success:
                std::cout << it.textStr << std::endl;
                break;
            case TextType::Error:
                std::cerr << it.textStr << std::endl;
                break;
        }
    }
}

std::string CmdController::getRaw(const Text &text){
    write(text);
    std::string line;
    std::getline(std::cin, line);
    return line;
}
