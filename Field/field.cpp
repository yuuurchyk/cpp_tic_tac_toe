#include "Field.h"

using namespace Field;
using std::vector;
using std::pair;
using std::make_pair;
using Exceptions::SameFieldsExceptions;

const int
    Field::kN = 3;

const vector<pair<int, int>>
    Field::kDelta = {
        {0, 1},
        {1, 0},
        {1, 1},
        {1, -1}
    };

vector<pair<int, int>> Field::initkCells(){
    vector<pair<int, int>> result;
    
    for(int i = 0; i < kN; i++)
        for(int j = 0; j < kN; j++)
            result.push_back(make_pair(i, j));
    
    return result;
}

const vector<pair<int, int>>
    Field::kCells = initkCells();

std::ostream& Field::operator<<(
    std::ostream &strm,
    const FieldInstance &field
)
{
    for(int i = 0; i < kN; i++){
        for(int j = 0; j < kN; j++)
            strm << field.get(make_pair(i, j));
        strm << std::endl;
    }

    return strm;
}

bool Field::is_valid(pair<int, int> cell_coordinates){
    return
        cell_coordinates.first >= 0 &&
        cell_coordinates.first < kN &&
        cell_coordinates.second >= 0 &&
        cell_coordinates.second < kN;
}

pair<int, int> Field::get_difference(
    const FieldInstance &l,
    const FieldInstance &r
)
{
    for(auto &it: kCells)
        if(l.get(it) != r.get(it))
            return it;
    
    throw SameFieldsExceptions();
}