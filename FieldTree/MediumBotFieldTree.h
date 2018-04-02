#ifndef MEDIUM_BOT_FIELD_TREE_
#define MEDIUM_BOT_FIELD_TREE_

#include <map>
#include <utility>
#include <list>

#include "../Field/Field.h"
#include "../Tokens/Tokens.h"

namespace TicTacToe{
    class MediumBotFieldTree{
    public:
        MediumBotFieldTree(
            const Field &field,
            const Player &current_player,
            const Player &target_player
        );

        ~MediumBotFieldTree();

        std::pair<int, int> predict() const;
        const Field& get_field() const;
        bool is_winning() const;

    private:
        MediumBotFieldTree(
            const Field &field,
            const Player &current_player,
            const Player &target_player,
            std::map<size_t, MediumBotFieldTree * const> * const storage
        );

        const Field field_;

        const Player
            &current_player_,
            &target_player_;
        
        bool
            is_winning_,
            is_root_;
        
        std::list<MediumBotFieldTree*> children_;
        std::map<size_t, MediumBotFieldTree * const> * const storage_;

        MediumBotFieldTree * const get(
            const Field &field,
            const Player &current_player,
            const Player &target_player
        );
        void grow();
        void init();
    };
}

#endif