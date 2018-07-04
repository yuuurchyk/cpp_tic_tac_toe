#ifndef GAME_H_
#define GAME_H_

#include "../Player/AbstractPlayer.h"
#include "../Tokens/Tokens.h"

namespace TicTacToe{
    class Game{
    public:
        Game(AbstractPlayer *playerX, AbstractPlayer *playerO, const Field &field);

        bool isEnd() const;
        bool isDraw() const;
        bool isWinner(Player *winner=nullptr) const;

        std::string getPlayerName(const Player &player) const;

        void makeMove();
    private:
        Player currentPlayer{Player::X()};
        AbstractPlayer
            *playerX,
            *playerO;
        const Field &field;
    };
}

#endif