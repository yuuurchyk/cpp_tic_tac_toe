#include <sstream>
#include <cctype>
#include <algorithm>

#include "AbstractController.h"
#include "../Exceptions/CommonExceptions.h"
#include "../Exceptions/ControllerExceptions.h"
#include "../Exceptions/FieldExceptions.h"

using namespace TicTacToe;

namespace{
    void checkField(Field const * field){
        if(field == nullptr)
            throw NullPointerError();
    }
}

const std::string
    AbstractController::kQuitStr{normalize("Quit")},
    AbstractController::kRestartStr{normalize("Restart")};

const Text AbstractController::kInfoText{
    TextEntry{
        TextType::Success,
        std::string("Type ") + AbstractController::kRestartStr + std::string(" to restart")
    },
    TextEntry{
        TextType::Error,
        std::string("Type ") + AbstractController::kQuitStr + std::string(" to quit")
    }
};

AbstractController::AbstractController(Field const * field):
    field(field)
{
    checkField(field);
}

void AbstractController::update(){
    checkField(field);
}

void AbstractController::update(Field const * newField){
    field = newField;
    update();
}

bool AbstractController::checkQuit(const std::string &str){
    if(str != kQuitStr)
        return false;
    if(select("Do you really want to quit?", Select{kNo, kYes}) == kYes)
        throw QuitError();
    return true;
}

bool AbstractController::checkRestart(const std::string &str){
    if(str != kRestartStr)
        return false;
    if(select("Do you really want to restart?", Select{kNo, kYes}) == kYes)
        throw RestartError();
    return true;
}

Option AbstractController::select(
    const std::string &message,
    const Select &select
){
    Text t{TextEntry(TextType::Success, message)};
    return this->select(t, select);
}

Option AbstractController::select(const Text &text, const Select &select){
    Text t(text);

    for(const auto &it: select){
        std::stringstream strm;
        strm << "    [" << it.shortcut << "] " << it.name;
        if(!it.explanation.empty())
            strm << "(" << it.explanation << ")";
        t.push_back(TextEntry(TextType::Regular, strm.str()));
    }
    
    bool wasWarning = false;
    while(true){
        std::string response = getRaw(t);

        if(checkQuit(response) || checkRestart(response)){
            if(wasWarning){
                wasWarning = false;
                t.pop_front();
            }
            continue;
        }
        
        for(const auto &it: select)
            if(it.shortcut == response)
                return it;
        
        if(!wasWarning){
            wasWarning = true;
            t.push_front(
                TextEntry(
                    TextType::Error,
                    std::string("Invalid data. Try again")
                )
            );
        }
    }
}

std::pair<size_t, size_t> AbstractController::getCoordinates(const Text &text){
    checkField(field);   

    Text localText(text);

    std::pair<size_t, size_t> res;

    while(true){
        std::stringstream strm(getRaw(localText));

        while(localText.height() > text.height())
            localText.pop_front();
        
        if(checkQuit(strm.str()) || checkRestart(strm.str()))
            continue;
        
        if(!(strm >> res.first) || !(strm >> res.second)){
            localText.push_front(
                TextEntry(
                    TextType::Error,
                    std::string("Invalid format. Try Again!")
                )
            );
            continue;
        }
        try{
            if(!field->isOccupied(res.first, res.second))
                return res;
            localText.push_front(
                TextEntry(
                    TextType::Error,
                    std::string("This cell is already occupied. Try Again!")
                )
            );
        }
        catch(const FieldOutOfBoundsError &e){
            localText.push_front(
                TextEntry(
                    TextType::Error,
                    std::string("Invalid cell coordinates. Try Again!")
                )
            );
            continue;
        }
    }

    throw InternalLogicError();
}

std::string AbstractController::getPlayerName(const Text &text){
    Text localText(text);

    while(true){
        std::string response = normalize(getRaw(localText));

        while(localText.height() > text.height())
            localText.pop_front();
        
        if(checkQuit(response) || checkRestart(response))
            continue;
        
        if(
            response.empty() || 
            static_cast<size_t>(
                std::count_if(
                    response.cbegin(),
                    response.cend(),
                    isspace
                )
            ) == response.size()
        ){
            localText.push_front(
                TextEntry(
                    TextType::Error,
                    std::string("Player name cannot be empty or consist of whitespaces")
                )
            );
            continue;
        }

        return response;
    }

    throw InternalLogicError();
}
