#include "HumanPlayer.h"

using namespace TicTacToe;

HumanPlayer::HumanPlayer(
    Field &field,
    std::istream &in_strm,
    std::ostream &out_strm,
    Player player,
    const std::string name
):
    AbstractPlayer
    (
        field,
        player,
        name
    ),
    in_strm(in_strm),
    out_strm(out_strm)
{}

void HumanPlayer::make_move(){
    std::string prompt{"Player " + name + ", enter your coordinates\n"};
    static const std::string fail{"Invalid characters\n"};

    for(bool was = false;; was=true){
        std::pair<int, int> cell =
            read_pair_with_message<int, int>(
                in_strm,
                out_strm,
                was? "" : prompt,
                fail
            );
        
        if(!is_valid(cell))
            out_strm << "Invalid cell. Try again" << std::endl;
        else if(field.is_occupied(cell))
            out_strm << "Cell is already occupied. Try again" << std::endl;
        else if(!field.set(cell, convert(player)))
            out_strm << "An error occured. Try again" << std::endl;
        else return;
    }
}

const std::string TicTacToe::get_human_player_name(
    std::istream &in_strm,
    std::ostream &out_strm,
    Player player
)
{
    static const std::string fail{"Name cannot contain whitespaces\n"};
    std::string prompt{
        "Player " +
        std::string(1, getChar(player)) +
        ", please enter your name\n"
    };

    return read_with_message<std::string>(
        in_strm,
        out_strm,
        prompt,
        fail
    );
}