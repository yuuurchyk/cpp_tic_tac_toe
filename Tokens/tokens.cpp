#include "Tokens.h"

using namespace Tokens;
using Exceptions::ConvertionException;

Cell Tokens::convert(const Player &player){
    switch(player){
        case Player::First:
            return Cell::First;
        case Player::Second:
            return Cell::Second;
        default:
            throw ConvertionException();
    }
}

Player Tokens::convert(const Cell &cell){
    switch(cell){
        case Cell::First:
            return Player::First;
        case Cell::Second:
            return Player::Second;
        default:
            throw ConvertionException();
    }
}