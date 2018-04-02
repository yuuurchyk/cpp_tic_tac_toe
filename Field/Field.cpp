#include "Field.h"

using namespace TicTacToe;
using std::vector;
using std::pair;
using std::make_pair;

const int
    TicTacToe::kN = 3;

const vector<pair<int, int>>
    TicTacToe::kDelta = {
        {0, 1},
        {1, 0},
        {1, 1},
        {1, -1}
    };

namespace{
    vector<pair<int, int>> initkCellsCoordinates(){
        vector<pair<int, int>> result;
        
        for(int i = 0; i < kN; i++)
            for(int j = 0; j < kN; j++)
                result.push_back(make_pair(i, j));
        
        return result;
    }
}

const vector<pair<int, int>>
    TicTacToe::kCellsCoordinates = initkCellsCoordinates();

Field::Field():
    is_draw_(false),
    is_winner_(false),
    winner_(Player::First),
    free_cells_left_(kN * kN)
{
    field_.clear();
    field_.resize(kN);

    for(int i = 0; i < kN; i++)
        field_[i].resize(kN, Cell::Empty);
    
    hash_ = 0;
    size_t p = 1;

    for(auto it: kCellsCoordinates){
        hash_ += getHash(get(it)) * p;
        p *= kHashBase;
    }
}

Field::Field(const Field &other){
    hash_ = other.hash_;
    field_ = other.field_;

    free_cells_left_ = other.free_cells_left_;

    is_draw_ = other.is_draw_;
    is_winner_ = other.is_winner_;
    winner_ = other.winner_;
}

Field& Field::operator=(const Field &other){
    if(&other == this)return *this;

    hash_ = other.hash_;
    field_ = other.field_;

    free_cells_left_ = other.free_cells_left_;

    is_draw_ = other.is_draw_;
    is_winner_ = other.is_winner_;
    winner_ = other.winner_;

    return *this;
}

bool Field::is_draw() const{
    return is_draw_;
}

bool Field::is_winner() const{
    return is_winner_;
}

bool Field::is_winner(const Player &player) const{
    if(!is_winner_)return false;
    return winner_ == player;
}

Cell Field::get(const pair<int, int> &cell_coordinates) const{
    if(!is_valid(cell_coordinates))throw InvalidCellException();

    return field_[cell_coordinates.first][cell_coordinates.second];
}

bool Field::set(
    const pair<int, int> &cell_coordinates,
    const Cell &cell
)
{
    if(!is_valid(cell_coordinates))
        throw InvalidCellException();
    if(cell == Cell::Empty)
        throw EmptyCellAssignmentException();
    if(is_draw() || is_winner())
        throw FullFieldAssignmentException();
    
    if(get(cell_coordinates) != Cell::Empty)
        return false;
    
    hash_ -= binary_power<size_t>(
        kHashBase,
        cell_coordinates.first * kN + cell_coordinates.second
    ) * getHash(get(cell_coordinates));

    hash_ += binary_power<size_t>(
        kHashBase,
        cell_coordinates.first * kN + cell_coordinates.second
    ) * getHash(cell);

    free_cells_left_--;
    field_[cell_coordinates.first][cell_coordinates.second] = cell;

    for(auto &cell_coordinates: kCellsCoordinates){
        if(get(cell_coordinates) == Cell::Empty)continue;

        Cell target = get(cell_coordinates);

        for(auto &d: kDelta){
            bool ok = true;

            pair<int, int> current_cell_coordinates = cell_coordinates;

            for
            (
                int step = 0;
                step < kN && ok;
                step++,
                current_cell_coordinates.first += d.first,
                current_cell_coordinates.second += d.second
            )
                if
                (
                    !is_valid(current_cell_coordinates) ||
                    get(current_cell_coordinates) != target
                )
                    ok = false;
            
            if(ok){
                is_winner_ = true;
                winner_= convert(target);
                return true;
            }
        }
    }

    if(free_cells_left_ == 0)
        is_draw_ = true;
    
    return true;
}

bool Field::is_occupied(const pair<int, int> &cell_coordinates) const{
    if(!is_valid(cell_coordinates))
        throw InvalidCellException();
    
    return field_[cell_coordinates.first][cell_coordinates.second] != Cell::Empty;
}

size_t Field::get_hash() const{
    return hash_;
}

std::ostream& TicTacToe::operator<<(
    std::ostream &strm,
    const Field &field
)
{
    for(int i = 0; i < kN; i++){
        for(int j = 0; j < kN; j++)
            strm << field.get(make_pair(i, j));
        strm << std::endl;
    }

    return strm;
}

bool TicTacToe::is_valid(pair<int, int> cell_coordinates){
    return
        cell_coordinates.first >= 0 &&
        cell_coordinates.first < kN &&
        cell_coordinates.second >= 0 &&
        cell_coordinates.second < kN;
}

pair<int, int> TicTacToe::get_difference(
    const Field &l,
    const Field &r
)
{
    for(auto &it: kCellsCoordinates)
        if(l.get(it) != r.get(it))
            return it;
    
    throw SameFieldsException();
}
