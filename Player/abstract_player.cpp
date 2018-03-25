#include "Player.h"

using namespace Player;

AbstractPlayer::AbstractPlayer(
    Field::FieldInstance &field,
    std::istream &in_strm,
    std::ostream &out_strm,
    bool is_first
):
    value(is_first? Field::kFirstPlayer : Field::kSecondPlayer),
    field(field),
    in_strm(in_strm),
    out_strm(out_strm)
    {}