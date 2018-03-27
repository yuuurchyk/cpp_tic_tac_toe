#include "FieldTree.h"

using namespace FieldTree;

FieldTreeExtended::FieldTreeExtended(
    Field::FieldInstance field,
    char player,
    char target_player,
    bool is_root
):
    player_(player),
    opposite_player_(Field::get_opposite_player(player_)),
    target_player_(target_player),
    field_(field),
    is_root_(is_root)
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
    if(is_root_){
        std::vector<std::thread> threads;
        std::mutex mux;

        for(int i = 0; i < Field::kN; i++)
            for(int j = 0; j < Field::kN; j++){
                std::pair<int, int> cell = std::make_pair(i, j);

                if(field_.is_occupied(cell))continue;

                Field::FieldInstance tmp{field_};
                tmp.set(cell, player_);
                threads.emplace_back(
                    &FieldTreeExtended::add,
                    tmp,
                    opposite_player_,
                    target_player_,
                    false,
                    std::ref(children_),
                    std::ref(mux));
            }
        
        for(auto &it: threads)
            it.join();
        
        return;
    }

    for(int i = 0; i < Field::kN; i++)
        for(int j = 0; j < Field::kN; j++){
            std::pair<int, int> cell = std::make_pair(i, j);

            if(field_.is_occupied(cell))continue;

            Field::FieldInstance tmp{field_};
            tmp.set(cell, player_);
            children_.emplace_back(tmp, opposite_player_, target_player_, false);
        }
}

void FieldTreeExtended::add(
    Field::FieldInstance field,
    char player,
    char target_player,
    bool is_root,
    std::vector<FieldTreeExtended> &target,
    std::mutex &mux
)
{
    std::lock_guard<std::mutex> lck(mux);
    target.emplace_back(field, player, target_player, is_root);
}