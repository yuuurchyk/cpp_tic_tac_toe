#include "Tokens.h"

using namespace Tokens;

char Tokens::getChar(const Player &player){
    switch(player){
        case Player::First:
            return 'X';
        case Player::Second:
            return 'O';
        default:
            return '-';
    }
}

std::ostream& Tokens::operator<<(std::ostream &strm, const Player &player){
    strm << getChar(player);
    return strm;
}

Player Tokens::opposite(const Player &player){
    if(player == Player::First)
        return Player::Second;
    return Player::First;
}