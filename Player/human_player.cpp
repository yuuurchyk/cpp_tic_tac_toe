#include "Player.h"

using namespace Player;

HumanPlayer::HumanPlayer(
    Field::FieldInstance &field,
    std::istream &in_strm,
    std::ostream &out_strm,
    Tokens::Player player,
    const std::string name
):
    AbstractPlayer
    (
        field,
        in_strm,
        out_strm,
        player,
        name
    )
    {}

void HumanPlayer::make_move(){
    std::string prompt{"Player " + name + ", enter your coordinates\n"};
    static const std::string fail{"Invalid characters\n"};

    for(bool was = false;; was=true){
        std::pair<int, int> cell =
            Read::read_pair_with_message<int, int>(
                in_strm,
                out_strm,
                was? "" : prompt,
                fail
            );
        
        if(!Field::is_valid(cell))
            out_strm << "Invalid cell. Try again" << std::endl;
        else if(field.is_occupied(cell))
            out_strm << "Cell is already occupied. Try again" << std::endl;
        else if(!field.set(cell, Tokens::convert(player)))
            out_strm << "An error occured. Try again" << std::endl;
        else return;
    }
}