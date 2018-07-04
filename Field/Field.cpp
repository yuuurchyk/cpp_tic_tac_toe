#include <utility>

#include "Field.h"
#include "../Exceptions/FieldExceptions.h"

using namespace TicTacToe;

Field::Field(){}

inline void Field::validate(size_t i, size_t j){
    if(i >= kN || j >= kN)
        throw FieldOutOfBoundsError();
}

std::ostream& TicTacToe::operator<<(std::ostream &strm, const Field &rhs){
    for(size_t i = 0; i < Field::kN; ++i)
    {
        for(size_t j = 0; j < Field::kN; ++j)
            strm << static_cast<char>(rhs(i, j));
        strm << ((i == Field::kN - 1) ? "" : "\n");
    }

    return strm;
}

bool Field::operator==(const Field &rhs) const{
    for(size_t i = 0; i < kN; ++i)
        for(size_t j = 0; j < kN; ++j)
            if(operator()(i, j) == rhs(i, j))
                return false;
    return true;
}

Field &Field::operator=(const Field &rhs){
    for(size_t i = 0; i < kN; ++i)
        for(size_t j = 0; j < kN; ++j)
            field_[i][j] = rhs(i, j);
    freeCellsLeft_ = rhs.freeCellsLeft_;
    return *this;
}

Field::Field(const Field &rhs){
    operator=(rhs);
}

Player Field::whooseMove() const{
    return (freeCellsLeft_ % 2 == (kN * kN) % 2)? Player::X(): Player::O();
}

Field::operator size_t() const{
    size_t p{1}, res{0};
    for(size_t i = 0; i < kN; ++i)
        for(size_t j = 0; j < kN; ++j, p *= Cell::kBase)
            res += p * static_cast<size_t>(operator()(i, j));
    return res;
}

bool Field::isOccupied(size_t i, size_t j) const{
    return at(i, j) != Cell::Empty();
}

void Field::set(size_t i, size_t j, const Player &p){
    if(at(i, j) != Cell::Empty())
        throw FieldCellOccupiedError(i, j);
    if(p != whooseMove())
        throw FieldMoveOrderError();
    --freeCellsLeft_;
    field_[i][j] = static_cast<Cell>(p);
}

const Cell& Field::operator()(size_t i, size_t j) const{
    return field_[i][j];
}

const Cell& Field::at(size_t i, size_t j) const{
    validate(i, j);
    return operator()(i, j);
}

bool Field::isWinner(Player *winner) const{
    static const std::array<std::pair<int, int>, 4>
        directions{
            std::make_pair(1, -1),
            std::make_pair(1, 0),
            std::make_pair(1, 1),
            std::make_pair(0, 1)
        };
    
    for(size_t i = 0; i < kN; ++i)
        for(size_t j = 0; j < kN; ++j){
            Cell current{operator()(i, j)};
            if(current == Cell::Empty())
                continue;

            for(const auto &d :directions){
                try{
                    size_t ti{i}, tj{j};
                    bool ok = true;
                    for(size_t t = 0; t < kN; ++t, ti += d.first, tj += d.second)
                        if(at(ti, tj) != current){
                            ok = false;
                            break;
                        }
                    if(ok){
                        if(winner != nullptr)
                            *winner = static_cast<Player>(current);
                        return true;
                    }
                }
                catch(const FieldOutOfBoundsError &e){
                    continue;
                }
            }
        }
    
    return false;
}

bool Field::isDraw() const{
    return (!isWinner()) && freeCellsLeft_ == 0;
}

std::pair<size_t, size_t> Field::difference(const Field &rhs) const{
    for(size_t i = 0; i < kN; ++i)
        for(size_t j = 0; j < kN; ++j)
            if(operator()(i, j) != rhs(i, j))
                return std::make_pair(i, j);
    throw FieldDifferenceError();
}