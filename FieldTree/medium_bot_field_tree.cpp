#include "FieldTree.h"

using namespace FieldTree;
using Field::FieldInstance;
using Field::kCellsCoordinates;
using Field::get_difference;
using Tokens::Player;
using Tokens::convert;
using Tokens::opposite;
using Exceptions::NoStorageProvidedException;
using Exceptions::InvalidPredictionException;
using Exceptions::FullFieldAssignmentException;
using Exceptions::InternalLogicException;

MediumBotFieldTree::MediumBotFieldTree(
    const FieldInstance &field,
    const Player &current_player,
    const Player &target_player
):
    field_(field),
    current_player_(current_player),
    target_player_(target_player),
    is_root_(true),
    storage_(new std::map<size_t, MediumBotFieldTree * const>)
{
    storage_->insert(std::make_pair(field.get_hash(), this));
    init();
}

MediumBotFieldTree::MediumBotFieldTree(
    const FieldInstance &field,
    const Player &current_player,
    const Player &target_player,
    std::map<size_t, MediumBotFieldTree * const> * const storage
):
    field_(field),
    current_player_(current_player),
    target_player_(target_player),
    is_root_(false),
    storage_(storage)
{
    init();
}

void MediumBotFieldTree::init(){
    if(storage_ == nullptr)
        throw NoStorageProvidedException();

    if(field_.is_draw() || field_.is_winner(target_player_)){
        is_winning_ = true;
        return;
    }
    if(field_.is_winner(opposite(target_player_))){
        is_winning_ = false;
        return;
    }

    grow();

    if(current_player_ == target_player_){
        is_winning_ = false;
        for(auto child: children_)
            if(child->is_winning()){
                is_winning_ = true;
                return;
            }
    }
    else{
        is_winning_ = true;
        for(auto child: children_)
            if(!child->is_winning()){
                is_winning_ = false;
                return;
            }
    }
}

void MediumBotFieldTree::grow(){
    for(auto &cell: kCellsCoordinates){
        if(field_.is_occupied(cell))continue;

        FieldInstance tmp{field_};
        if(!tmp.set(cell, convert(current_player_))) continue;

        children_.push_back(get(tmp, opposite(current_player_), target_player_));
    }
}

MediumBotFieldTree * const MediumBotFieldTree::get(
    const FieldInstance &field,
    const Player &current_player,
    const Player &target_player
)
{
    auto itr = storage_->find(field.get_hash());
    if(itr != storage_->end())
        return itr->second;
    
    MediumBotFieldTree * tmp = new MediumBotFieldTree(
        field,
        current_player,
        target_player,
        storage_
    );

    storage_->insert(std::make_pair(field.get_hash(),tmp));

    return storage_->at(field.get_hash());
}

MediumBotFieldTree::~MediumBotFieldTree(){
    if(is_root_){
        for(auto itr=storage_->begin(); itr != storage_->end(); ++itr)
            if(itr->second != this)
                delete itr->second;
        
        delete storage_;
    }
}

bool MediumBotFieldTree::is_winning() const{
    return is_winning_;
}

const FieldInstance& MediumBotFieldTree::get_field() const{
    return field_;
}

std::pair<int, int> MediumBotFieldTree::predict() const{
    if(target_player_ != current_player_)
        throw InvalidPredictionException();
    
    if(children_.size() == 0)
        throw FullFieldAssignmentException();
    
    if(!is_winning_)
        return get_difference(field_, (*children_.begin())->get_field());
    
    for(auto child: children_)
        if(child->is_winning())
            return get_difference(field_, child->get_field());
    
    throw InternalLogicException();
}