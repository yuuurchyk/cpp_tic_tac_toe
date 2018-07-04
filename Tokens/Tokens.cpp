#include "Tokens.h"
#include "../Exceptions/TokensExceptions.h"
#include "../Exceptions/CommonExceptions.h"

using namespace TicTacToe;

Cell::Cell(size_t type):
    type_(type)
{}

Cell::Cell(const Cell &rhs):
    type_(rhs.type_)
{}

bool Cell::operator==(const Cell &rhs) const{
    return type_ == rhs.type_;
}
bool Cell::operator!=(const Cell &rhs) const{
    return !(operator==(rhs));
}

Cell& Cell::operator=(const Cell &rhs){
    type_ = rhs.type_;
    return *this;
}

Cell Cell::Empty(){
    return Cell(kEmptyType);
}
Cell::Cell():
    Cell(kEmptyType)
{}
Cell Cell::X(){
    return Cell(kXType);
}
Cell Cell::O(){
    return Cell(kOType);
}
Cell::operator char() const{
    switch(type_){
        case kEmptyType:
            return '-';
        case kXType:
            return 'X';
        case kOType:
            return 'O';
    }
    throw InternalLogicError();
}


std::ostream& TicTacToe::operator<<(std::ostream &strm, const Cell &rhs){
    strm << static_cast<char>(rhs);
    return strm;
}

Cell::operator Player() const{
    if(operator==(Cell::Empty()))
        throw TokensConvertionError();
    if(operator==(Cell::X()))
        return Player::X();
    return Player::O();
}

Cell::operator size_t() const{
    return type_;
}

Player::Player(size_t type):
    type_(type)
{}

Player::Player(const Player &rhs):
    type_(rhs.type_)
{}

bool Player::operator==(const Player &rhs) const{
    return type_ == rhs.type_;
}
bool Player::operator!=(const Player &rhs) const{
    return !(operator==(rhs));
}

Player& Player::operator=(const Player &rhs){
    type_ = rhs.type_;
    return *this;
}

Player Player::X(){
    return Player(kXType);
}
Player Player::O(){
    return Player(kOType);
}
Player::operator char() const{
    switch(type_){
        case kXType:
            return 'X';
        case kOType:
            return 'O';
    }
    throw InternalLogicError();
}

std::ostream& TicTacToe::operator<<(std::ostream &strm, const Player &rhs){
    strm << static_cast<char>(rhs);
    return strm;
}

Player::operator Cell() const{
    if(operator==(Player::X()))
        return Cell::X();
    return Cell::O();
}

Player::operator size_t() const{
    return type_;
}

Player& Player::toggle(){
    type_ ^= 1;
    return *this;
}