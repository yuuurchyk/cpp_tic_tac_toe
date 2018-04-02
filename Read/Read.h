#ifndef READ_H_
#define READ_H_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

namespace TicTacToe{
    template<class T>
    T read_with_message(
        std::istream &input,
        std::ostream &output,
        std::string prompt_msg,
        std::string fail_msg
    );

    template<class F, class S>
    std::pair<F, S> read_pair_with_message(
        std::istream &input,
        std::ostream &output,
        std::string prompt_msg,
        std::string fail_msg
    );
}

#include "read_pair_with_message_imp.h"
#include "read_with_message_imp.h"

#endif