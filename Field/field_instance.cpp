#include "Field.h"

using namespace Field;
using namespace Tokens;

FieldInstance::FieldInstance():
    is_draw_(false),
    is_winner_(false),
    winner_(Player::First)
{
    field_.clear();
    field_.resize(kN);

    for(int i = 0; i < kN; i++)
        field_[i].resize(kN, Cell::Empty);
    
    hash_ = 0;
    size_t p = 1;

    for(auto it: kCells){
        hash_ += getHash(get(it)) * p;
        p *= kHashBase;
    }

    
}