#include "Player.h"

using namespace Player;

EasyBot::EasyBot(
    Field::FieldInstance &field,
    std::istream &in_strm,
    std::ostream &out_strm,
    bool is_first,
    const std::string name
):
    AbstractPlayer
    (
        field,
        in_strm,
        out_strm,
        is_first,
        name
    )
    {}

void EasyBot::make_move(){
    FieldTree::FieldTreeSimple tree{Field::FieldInstance{field}, value};
    field.set(tree.predict(), value); 
}