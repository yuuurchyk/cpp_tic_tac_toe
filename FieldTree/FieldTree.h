#ifndef FIELD_TREE_H_
#define FIELD_TREE_H_

#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <cmath>

#include "../Field/Field.h"

namespace FieldTree{
    class FieldTreeSimple{
    public:
        FieldTreeSimple(
            Field::FieldInstance field,
            char value
        );

        int get_winning(char value) const;
        Field::FieldInstance get_field() const;

        std::pair<int, int> predict() const;
    private:
        void grow();

        Field::FieldInstance field;
        std::vector<FieldTreeSimple> children;

        std::map<char, int> winnings;
        char value, reversed_value;
    };
}

#endif