#include "Tokens.h"

using namespace Tokens;

const size_t
    Tokens::kHashBase = Field::kN;

char Tokens::getChar(const Cell &cell){
    switch(cell){
        case Cell::First:
            return 'X';
        case Cell::Second:
            return 'O';
        default:
            return '-';
    }
}

size_t Tokens::getHash(const Cell &cell){
    switch(cell){
        case Cell::Empty:
            return 0;
        case Cell::First:
            return 1;
        case Cell::Second:
            return 2;
    }
}

std::ostream& Tokens::operator<<(std::ostream &strm, const Cell &cell){
    strm << getChar(cell);
    return strm;
}