#include "FieldTree.h"

using namespace FieldTree;

FieldTreeExtended::FieldTreeExtended(
    Field::FieldInstance field,
    char player,
    char target_player
):
    player_(player),
    opposite_player_(Field::get_opposite_player(player_)),
    target_player_(target_player),
    field_(field)
{
    char winner = field_.is_winner();

    if(winner != Field::kEmpty || field.get_free_cells_left() == 0){
        if(field.get_free_cells_left() == 0)
            is_winning_ = true;
        if(winner == target_player_)
            is_winning_ = true;
    }
    else{
        grow();

        if(player_ == target_player_){
            for(auto &child: children_)
                if(child.is_winning()){
                    is_winning_ = true;
                    break;
                }
        }
        else{
            is_winning_ = true;
            for(auto &child: children_)
                if(!child.is_winning()){
                    is_winning_ = false;
                    break;
                }
        }
    }
}

bool FieldTreeExtended::is_winning() const{
    return is_winning_;
}

Field::FieldInstance FieldTreeExtended::get_field() const{
    return field_;
}

std::pair<int, int> FieldTreeExtended::predict() const{
    Field::FieldInstance result;

    if(!is_winning_)
        result = children_[0].get_field();
    else{
        for(auto &child: children_)
            if(child.is_winning()){
                result = child.get_field();
                break;
            }
    }

    for(int i = 0; i < Field::kN; i++)
        for(int j = 0; j < Field::kN; j++){
            std::pair<int, int> cell = std::make_pair(i, j);
            if(field_.get(cell) != result.get(cell))
                return cell;
        }
}

void FieldTreeExtended::grow(){
    for(int i = 0; i < Field::kN; i++)
        for(int j = 0; j < Field::kN; j++){
            std::pair<int, int> cell = std::make_pair(i, j);

            if(field_.is_occupied(cell))continue;

            Field::FieldInstance tmp{field_};
            tmp.set(cell, player_);

            children_.emplace_back(tmp, opposite_player_, target_player_);
        }
}