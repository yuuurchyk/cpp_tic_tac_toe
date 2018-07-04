#include <iostream>

#include "Controller/Controller.h"
#include "Exceptions/Exceptions.h"
#include "Game/Game.h"
#include "Player/Player.h"
#include "Text/Text.h"

using namespace TicTacToe;

namespace TicTacToe{
    const std::string kHelpToken{"--help"};
}

int main(int argc, char ** argv){
    if(argc != 2){
        std::cerr << "Invalid number of arguments" << std::endl;
        std::cerr << "Run with " << kHelpToken << " to get help" << std::endl;
        return EXIT_FAILURE;
    }

    ++argv;
    if(std::string(*argv) == kHelpToken){
        std::cout << "run with `" << kCmdControllerToken << "` to have cmd interface" << std::endl;
        std::cout << "run with `" << kGuiControllerToken << "` to have gui interface" << std::endl;
        return EXIT_SUCCESS;
    }

    auto field = new Field();
    auto controller = getController(field, std::string(*argv));

    AbstractPlayer *playerX{nullptr};
    AbstractPlayer *playerO{nullptr};

    Game *game{nullptr};

    if(controller == nullptr){
        delete field;
        std::cerr << "Invalid argument" << std::endl;
        std::cerr << "Run with " << kHelpToken << " to get help" << std::endl;
        return EXIT_FAILURE;
    }

    while(true){
        try{
            playerX = getPlayer(*field, Player::X(), controller);
            playerO = getPlayer(*field, Player::O(), controller);

            game = new Game(playerX, playerO, *field);

            do{
                controller->update();
                game->makeMove();
            }
            while(!game->isEnd());
            controller->update();

            Text t;

            {
                if(game->isDraw())
                    t.push_back(TextEntry(TextType::Error, std::string("It is a draw")));
                else{
                    Player winner = Player::X();
                    game->isWinner(&winner);
                    t.push_back(
                        TextEntry(
                            TextType::Success,
                            game->getPlayerName(winner) + " won!"
                        )
                    );
                }
                t.push_back(TextEntry(TextType::Regular, "Would you like to player again?"));
            }

            if(controller->select(t, Select({kYes, kNo})) == kYes)
                throw RestartError();
            throw QuitError();
        }
        catch(const QuitError &e){
            delete controller;
            delete field;
            delete playerX;
            delete playerO;
            delete game;
            return EXIT_SUCCESS;
        }
        catch(const RestartError &e){
            delete playerX;
            delete playerO;
            delete game;
            delete field;
            field = new Field();
            controller->update(field);
            continue;
        }
        catch(const TicTacToeError &e){
            delete controller;
            delete field;
            delete playerX;
            delete playerO;
            delete game;
            std::cerr << "The following exception occured:" << std::endl;
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }

    throw InternalLogicError();
}