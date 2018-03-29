#ifndef FIELD_TREE_H_
#define FIELD_TREE_H_

#include <map>
#include <utility>
#include <list>

#include "../Field/Field.h"
#include "../Tokens/Tokens.h"

namespace FieldTree{
    class MediumBotFieldTree{
    public:
        MediumBotFieldTree(
            const Field::FieldInstance &field,
            const Tokens::Player &current_player,
            const Tokens::Player &target_player
        );

        ~MediumBotFieldTree();

        std::pair<int, int> predict() const;
        const Field::FieldInstance& get_field() const;
        bool is_winning() const;

    private:
        MediumBotFieldTree(
            const Field::FieldInstance &field,
            const Tokens::Player &current_player,
            const Tokens::Player &target_player,
            std::map<size_t, MediumBotFieldTree * const> * const storage
        );

        const Field::FieldInstance field_;

        const Tokens::Player
            &current_player_,
            &target_player_;
        
        bool
            is_winning_,
            is_root_;
        
        std::list<MediumBotFieldTree*> children_;
        std::map<size_t, MediumBotFieldTree * const> * const storage_;

        MediumBotFieldTree * const get(
            const Field::FieldInstance &field,
            const Tokens::Player &current_player,
            const Tokens::Player &target_player
        );
        void grow();
        void init();
    };
}

#endif