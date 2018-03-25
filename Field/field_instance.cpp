#include "Field.h"

using namespace Field;

using std::pair;
using std::make_pair;

std::ostream& Field::operator<<(std::ostream &strm, const FieldInstance &field){
    for(int i = 0; i < kN; i++)
        for(int j = 0; j < kN; j++)
            strm << 
                field.get(make_pair(i, j)) << 
                ((j == kN - 1)? '\n': ' ');
    
    return strm;
}

FieldInstance::FieldInstance(){
    free_cells_left = kN * kN;
    field.clear();
    field.resize(kN);
    for(int i = 0; i < kN; i++)
        field[i].resize(kN, kEmpty);
}
FieldInstance::FieldInstance(const FieldInstance &other){
    this->free_cells_left = other.free_cells_left;
    this->field = other.field;
}
FieldInstance& FieldInstance::operator=(const FieldInstance &other){
    if(&other == this)return *this;

    this->free_cells_left = other.free_cells_left;
    this->field = other.field;

    return *this;
}

char FieldInstance::get(pair<int, int> cell) const{
    if(!valid(cell))return kEmpty;

    return field[cell.first][cell.second];
}

bool FieldInstance::is_occupied(pair<int, int> cell) const{
    if(!valid(cell))return false;

    return field[cell.first][cell.second] != kEmpty;
}

bool FieldInstance::set(pair<int, int> cell, char value){
    if(!valid(cell))return false;
    if(kPlayersTokens.find(value) == kPlayersTokens.end())return false;
    if(is_occupied(cell))return false;

    field[cell.first][cell.second] = value;
    free_cells_left--;
}

bool FieldInstance::is_winner(char *winner) const{
    for(int i = 0; i < kN; i++)
        for(int j = 0; j < kN; j++){

            char value = field[i][j];
            if(value == kEmpty)continue;

            for(int d = 0; d < kDelta.size(); d++){
                bool ok = true;

                for
                (
                    int q = 0, ti = i, tj = j;
                    q < kN && ok;
                    q++, ti += kDelta[d].first, tj += kDelta[d].second
                )
                {
                    if(!valid(make_pair(ti, tj)) || field[ti][tj] != value)
                        ok = false;
                }

                if(ok){
                    *winner = field[i][j];
                    return true;
                }
            }
        }
    
    return false;
}

bool FieldInstance::is_draw() const{
    char tmp;
    return free_cells_left == 0 && !is_winner(&tmp);
}