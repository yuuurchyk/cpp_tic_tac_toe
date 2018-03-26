#include "Field.h"

const int Field::kN = 3;

const std::vector<std::pair<int, int>>
    Field::kDelta = {
        std::make_pair(0, 1),
        std::make_pair(1, 0),
        std::make_pair(1, 1),
        std::make_pair(-1, 1)
    };

const char
    Field::kFirstPlayer = 'X',
    Field::kSecondPlayer = 'O',
    Field::kEmpty = '-';

const std::set<char>
    Field::kPlayersTokens{
        Field::kFirstPlayer,
        Field::kSecondPlayer
    };

bool Field::valid(std::pair<int, int> cell){
    return 
        cell.first >= 0 &&
        cell.first < Field::kN &&
        cell.second >= 0 &&
        cell.second < Field::kN;
}

char Field::get_opposite_player(char player){
    if(player == Field::kFirstPlayer)
        return Field::kSecondPlayer;
    return Field::kFirstPlayer;
}