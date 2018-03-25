#include "Player.h"

using namespace Player;

HumanPlayer::HumanPlayer(
    Field::FieldInstance &field,
    std::istream &in_strm,
    std::ostream &out_strm,
    bool is_first
) :
    AbstractPlayer(field, in_strm, out_strm, is_first)
    {}

// std::string HumanPlayer::get_name(){
//     const std::string prompt =
//         "Player " +
//         std::string(1, value) +
//         ", enter your name:";
//     const std::string fail{"Name cannot consist only of whitespaces"};

//     return Read::read_with_message<std::string>(
//         in_strm,
//         out_strm,
//         prompt,
//         fail
//     );
// }

void HumanPlayer::make_move(){
    const std::string prompt = 
        "Player " +
        std::string(1, value) +
        ", enter your coordinates";
    static const std::string fail{"Invalid characters"};

    while(true){
        std::pair<int, int> cell =
            Read::read_pair_with_message<int, int>(
                in_strm,
                out_strm,
                prompt,
                fail
            );
        
        if(!Field::valid(cell))
            out_strm << "Invalid cell. Try again" << std::endl;
        else if(field.is_occupied(cell))
            out_strm << "Cell is already occupied. Try again" << std::endl;
        else if(!field.set(cell, value))
            out_strm << "An error occured. Try again" << std::endl;
        else return;
    }
}