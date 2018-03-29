#include "Player.h"

using namespace Player;

MediumBot::MediumBot(
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

void MediumBot::make_move(){
    FieldTree::MediumBotFieldTree tree(
        field,
        player,
        player
    );

    field.set(tree.predict(), Tokens::convert(player));
}