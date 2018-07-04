#ifndef SELECT_H_
#define SELECT_H_

#include <initializer_list>
#include <vector>
#include <utility>

#include "Option.h"

namespace TicTacToe{
    class Select{
    public:
        typedef std::vector<Option>::iterator iterator;
        typedef std::vector<Option>::const_iterator const_iterator;

        Select(const std::initializer_list<Option> &lst);

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;
    private:
        std::vector<Option> options{};
    };
};

#endif