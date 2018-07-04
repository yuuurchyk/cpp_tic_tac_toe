#include "MediumBotFieldTree.h"
#include "../Exceptions/CommonExceptions.h"
#include "../Exceptions/FieldTreeExceptions.h"

using namespace TicTacToe;

MediumBotFieldTree::MediumBotFieldTree(
    const Field &field,
    const Player &currentPlayer
):
    field_(field),
    currentPlayer_(currentPlayer),
    targetPlayer_(currentPlayer),
    isRoot_(true),
    storage_(new std::map<size_t, MediumBotFieldTree * const>)
{
    storage_->insert(std::make_pair(static_cast<size_t>(field), this));
    init();
}

MediumBotFieldTree::MediumBotFieldTree(
    const Field &field,
    const Player &current_player,
    const Player &target_player,
    std::map<size_t, MediumBotFieldTree * const> * const storage
):
    field_(field),
    currentPlayer_(current_player),
    targetPlayer_(target_player),
    isRoot_(false),
    storage_(storage)
{
    init();
}

void MediumBotFieldTree::init(){
    if(storage_ == nullptr)
        throw NullPointerError();

    bool draw = field_.isDraw();

    Player winner = Player::X();
    bool isWinner = field_.isWinner(&winner);

    if(draw || (isWinner && winner == targetPlayer_)){
        isWinning_ = true;
        return;
    }
    if(isWinner && winner == Player(targetPlayer_).toggle()){
        isWinning_ = false;
        return;
    }

    grow();

    if(currentPlayer_ == targetPlayer_){
        isWinning_ = false;
        for(auto child: children_)
            if(child->isWinning()){
                isWinning_ = true;
                return;
            }
    }
    else{
        isWinning_ = true;
        for(auto child: children_)
            if(!child->isWinning()){
                isWinning_ = false;
                return;
            }
    }
}

void MediumBotFieldTree::grow(){
    for(size_t i = 0; i < Field::kN; ++i)
        for(size_t j = 0; j < Field::kN; ++j){
            if(field_.isOccupied(i, j))continue;

            Field tmp{field_};
            tmp.set(i, j, currentPlayer_);

            children_.push_back(get(tmp, Player(currentPlayer_).toggle(), targetPlayer_));
        }
}

MediumBotFieldTree * const MediumBotFieldTree::get(
    const Field &field,
    const Player &current_player,
    const Player &target_player
)
{
    auto itr = storage_->find(static_cast<size_t>(field));
    if(itr != storage_->end())
        return itr->second;
    
    MediumBotFieldTree * tmp = new MediumBotFieldTree(
        field,
        current_player,
        target_player,
        storage_
    );

    storage_->insert(std::make_pair(static_cast<size_t>(field),tmp));

    return storage_->at(static_cast<size_t>(field));
}

MediumBotFieldTree::~MediumBotFieldTree(){
    if(isRoot_){
        for(auto itr=storage_->begin(); itr != storage_->end(); ++itr)
            if(itr->second != this)
                delete itr->second;
        
        delete storage_;
    }
}

bool MediumBotFieldTree::isWinning() const{
    return isWinning_;
}

const Field& MediumBotFieldTree::getField() const{
    return field_;
}

std::pair<size_t, size_t> MediumBotFieldTree::predict() const{
    if(targetPlayer_ != currentPlayer_)
        throw FieldTreePredictionError();
    
    if(children_.size() == 0)
        throw FieldTreeFullFieldPredictionError();
    
    if(!isWinning_)
        return field_.difference((*children_.begin())->getField());
    
    for(auto child: children_)
        if(child->isWinning())
            return field_.difference(child->getField());
    
    throw InternalLogicError();
}
