#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <utility>

#include "../Field/Field.h"
#include "../Read/Read.h"

namespace Player{
    class AbstractPlayer{
    public:

        AbstractPlayer(
            Field::FieldInstance &field,
            std::istream &in_strm,
            std::ostream &out_strm,
            bool is_first
        );

        virtual void make_move() = 0;

    protected:
        Field::FieldInstance &field;

        const char value;

        std::ostream &out_strm;
        std::istream &in_strm;
    };

    class HumanPlayer : public AbstractPlayer{
    public:
        HumanPlayer(
            Field::FieldInstance &field,
            std::istream &in_strm,
            std::ostream &out_strm,
            bool is_first
        );

        void make_move();
    };
}

#endif