#include "Player.h"

using namespace Player;

SillyBot::SillyBot(
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

void SillyBot::make_move(){
    while(true){
        std::pair<int, int> cell =
            std::make_pair(
                Common::get_random_number(0, Field::kN - 1),
                Common::get_random_number(0, Field::kN - 1)
            );
        
        if(field.set(cell, value))return;
    }
}