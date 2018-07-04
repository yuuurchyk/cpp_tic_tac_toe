#ifndef MEDIUM_BOT_FIELD_TREE_
#define MEDIUM_BOT_FIELD_TREE_

#include <map>
#include <utility>
#include <list>
#include <cstddef>

#include "../Field/Field.h"
#include "../Tokens/Tokens.h"

namespace TicTacToe{
    class MediumBotFieldTree{
    public:
        MediumBotFieldTree(
            const Field &field,
            const Player &currentPlayer
        );

        ~MediumBotFieldTree();

        std::pair<size_t, size_t> predict() const;
        const Field& getField() const;
        bool isWinning() const;

    private:
        MediumBotFieldTree(
            const Field &field,
            const Player &currentPlayer,
            const Player &targetPlayer,
            std::map<size_t, MediumBotFieldTree * const> * const storage
        );

        const Field field_;

        const Player
            &currentPlayer_,
            &targetPlayer_;
        
        bool
            isWinning_,
            isRoot_;
        
        std::list<MediumBotFieldTree*> children_;
        std::map<size_t, MediumBotFieldTree * const> * const storage_;

        MediumBotFieldTree * const get(
            const Field &field,
            const Player &currentPlayer,
            const Player &targetPlayer
        );
        void grow();
        void init();
    };
}

#endif