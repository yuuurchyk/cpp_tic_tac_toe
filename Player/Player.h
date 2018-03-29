#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <utility>
#include <vector>

#include "../Field/Field.h"
#include "../Read/Read.h"
#include "../Common/Common.h"
#include "../FieldTree/FieldTree.h"
#include "../Tokens/Tokens.h"

namespace Player{
    class AbstractPlayer{
    public:

        AbstractPlayer(
            Field::FieldInstance &field,
            std::istream &in_strm,
            std::ostream &out_strm,
            Tokens::Player player,
            const std::string name
        );

        virtual void make_move() = 0;
        std::string get_name() const;
        const Tokens::Player& get_player() const;
    
    protected:
        Field::FieldInstance &field;

        const Tokens::Player player;
        const std::string name;

        std::ostream &out_strm;
        std::istream &in_strm;
    };

    class HumanPlayer : public AbstractPlayer{
    public:
        HumanPlayer(
            Field::FieldInstance &field,
            std::istream &in_strm,
            std::ostream &out_strm,
            Tokens::Player player,
            const std::string name
        );

        void make_move();
    };

    class MediumBot : public AbstractPlayer{
    public:
        MediumBot(
            Field::FieldInstance &field,
            std::istream &in_strm,
            std::ostream &out_strm,
            Tokens::Player player,
            const std::string name
        );

        void make_move();
    };

    const std::string get_human_player_name(
        std::istream &in_strm,
        std::ostream &out_strm,
        Tokens::Player player
    );

    extern const std::vector<std::string> medium_bot_names;
    const std::string get_medium_bot_player_name();
}

#endif