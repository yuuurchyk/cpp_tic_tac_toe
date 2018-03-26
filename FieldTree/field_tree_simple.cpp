#include "FieldTree.h"

using namespace FieldTree;

FieldTreeSimple::FieldTreeSimple(
    Field::FieldInstance field,
    char value
):
    value(value),
    reversed_value(
        value == Field::kFirstPlayer?
        Field::kSecondPlayer : Field::kFirstPlayer),
    field(Field::FieldInstance(field))
{
    if(field.get_free_cells_left() == 0)
        winnings[field.is_winner()]++;
    else{
        grow();
        for(auto &child: children){
            winnings[Field::kEmpty] +=
                child.get_winning(Field::kEmpty);
            winnings[Field::kFirstPlayer] +=
                child.get_winning(Field::kFirstPlayer);
            winnings[Field::kSecondPlayer] +=
                child.get_winning(Field::kSecondPlayer);
        }
    }
}

int FieldTreeSimple::get_winning(char value) const{
    auto itr = winnings.find(value);
    if(itr == winnings.end())return 0;

    return itr->second;
}

std::pair<int, int> FieldTreeSimple::predict() const{
    int max_balance = -(1e9 + 5);
    
    for(auto &child: children){
        int current_balance = 
            child.get_winning(value) -
            child.get_winning(reversed_value);
        max_balance = std::max(max_balance, current_balance);
    }

    for(auto &child: children){
        int current_balance =
            child.get_winning(value) -
            child.get_winning(reversed_value);
        if(current_balance == max_balance){
            Field::FieldInstance result = child.get_field();
            for(int i = 0; i < Field::kN; i++)
                for(int j = 0; j < Field::kN; j++){
                    std::pair<int, int> cell = std::make_pair(i, j);
                    if(field.get(cell) != result.get(cell))
                        return cell;
                }
        }
    }
}

Field::FieldInstance FieldTreeSimple::get_field() const{
    return field;
}

void FieldTreeSimple::grow(){
    for(int i = 0; i < Field::kN; i++)
        for(int j = 0; j < Field::kN; j++){
            if(field.is_occupied(std::make_pair(i, j)))continue;

            Field::FieldInstance tmp{field};
            tmp.set(std::make_pair(i, j), value);

            children.emplace_back(tmp, reversed_value);
        }
}