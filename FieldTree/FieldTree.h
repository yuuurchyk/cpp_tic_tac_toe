#ifndef FIELD_TREE_H_
#define FIELD_TREE_H_

#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <cmath>
#include <mutex>
#include <thread>

#include <iostream>

#include "../Field/Field.h"

namespace FieldTree{
    class FieldTreeSimple{
    public:
        FieldTreeSimple(
            Field::FieldInstance field,
            char player
        );

        int get_number_of_winning_potisions(char player) const;
        Field::FieldInstance get_field() const;

        std::pair<int, int> predict() const;
    private:
        int get_balance(const FieldTreeSimple &child) const;

        const Field::FieldInstance field_;
        const char player_, opposite_player_;

        std::vector<FieldTreeSimple> children_;
        std::map<char, int> winnings_;

        void grow();
    };

    class FieldTreeExtended{
    public:
        FieldTreeExtended(
            Field::FieldInstance field,
            char player,
            char target_player,
            bool is_root=true
        );
    
        bool is_winning() const;
        Field::FieldInstance get_field() const;

        std::pair<int, int> predict() const;

        static void add
        (
            Field::FieldInstance field,
            char player,
            char target_player,
            bool is_root,
            std::vector<FieldTreeExtended> &target,
            std::mutex &mux
        );
    private:
        const Field::FieldInstance field_;
        const char player_, opposite_player_;
        const char target_player_;

        const bool is_root_;

        bool is_winning_{false};
        std::vector<FieldTreeExtended> children_;

        void grow();
    };
}

#endif