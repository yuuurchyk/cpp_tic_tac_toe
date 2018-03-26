#include "FieldTree.h"

using namespace FieldTree;

FieldTreeSimple::FieldTreeSimple(
    Field::FieldInstance field,
    char player
):
    player_(player),
    opposite_player_(Field::get_opposite_player(player)),
    field_(field)
{
    char winner = field.is_winner();
    if(field_.get_free_cells_left() == 0 || winner != Field::kEmpty)
        winnings_[field.is_winner()]++;
    else{
        grow();
        for(auto &child: children_){
            winnings_[Field::kEmpty] +=
                child.get_number_of_winning_potisions(Field::kEmpty);
            winnings_[Field::kFirstPlayer] +=
                child.get_number_of_winning_potisions(Field::kFirstPlayer);
            winnings_[Field::kSecondPlayer] +=
                child.get_number_of_winning_potisions(Field::kSecondPlayer);
        }
    }
}

int FieldTreeSimple::get_number_of_winning_potisions(char value) const{
    auto itr = winnings_.find(value);
    if(itr == winnings_.end())return 0;

    return itr->second;
}

int FieldTreeSimple::get_balance(const FieldTreeSimple &child) const{
    return
        child.get_number_of_winning_potisions(player_) -
        child.get_number_of_winning_potisions(opposite_player_);
}

std::pair<int, int> FieldTreeSimple::predict() const{
    int max_balance = INT_MIN;
    
    for(auto &child: children_)
        max_balance = std::max(max_balance, get_balance(child));

    Field::FieldInstance result;
    for(auto &child: children_)
        if(get_balance(child) == max_balance){
            result = child.get_field();
            break;
        }
    
    for(int i = 0; i < Field::kN; i++)
        for(int j = 0; j < Field::kN; j++){
            std::pair<int, int> cell = std::make_pair(i, j);
            if(field_.get(cell) != result.get(cell))
                return cell;
        }
}

Field::FieldInstance FieldTreeSimple::get_field() const{
    return field_;
}

void FieldTreeSimple::grow(){
    for(int i = 0; i < Field::kN; i++)
        for(int j = 0; j < Field::kN; j++){
            if(field_.is_occupied(std::make_pair(i, j)))continue;

            Field::FieldInstance tmp{field_};
            tmp.set(std::make_pair(i, j), player_);

            children_.emplace_back(tmp, opposite_player_);
        }
}