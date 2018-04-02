#include "Tokens.h"

using namespace TicTacToe;

const size_t
    TicTacToe::kHashBase = 3;

size_t TicTacToe::getHash(const Cell &cell){
    switch(cell){
        case Cell::Empty:
            return 0;
        case Cell::First:
            return 1;
        case Cell::Second:
            return 2;
    }
}

char TicTacToe::getChar(const Cell &cell){
    switch(cell){
        case Cell::First:
            return 'X';
        case Cell::Second:
            return 'O';
        default:
            return '-';
    }
}

Player TicTacToe::convert(const Cell &cell){
    switch(cell){
        case Cell::First:
            return Player::First;
        case Cell::Second:
            return Player::Second;
        default:
            throw ConvertionException();
    }
}

std::ostream& TicTacToe::operator<<(std::ostream &strm, const Cell &cell){
    strm << getChar(cell);
    return strm;
}

Player TicTacToe::opposite(const Player &player){
    if(player == Player::First)
        return Player::Second;
    return Player::First;
}

char TicTacToe::getChar(const Player &player){
    switch(player){
        case Player::First:
            return 'X';
        case Player::Second:
            return 'O';
        default:
            return '-';
    }
}

Cell TicTacToe::convert(const Player &player){
    switch(player){
        case Player::First:
            return Cell::First;
        case Player::Second:
            return Cell::Second;
        default:
            throw ConvertionException();
    }
}

std::ostream& TicTacToe::operator<<(std::ostream &strm, const Player &player){
    strm << getChar(player);
    return strm;
}