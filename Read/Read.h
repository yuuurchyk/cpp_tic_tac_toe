#ifndef READ_H_
#define READ_H_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

namespace Read{
    template<class T>
    T read_without_message(std::istream &input);
    // reads instance of type T and returns it.
    // if user entered wrong data, asks again
    template<class T>
    T read_with_message(
        std::istream &input,
        std::ostream &output,
        std::string prompt_msg,
        std::string fail_msg
    );
    // the same but with alerting message

    template<class F, class S>
    std::pair<F, S> read_pair_without_message(std::istream &input);
    template<class F, class S>
    std::pair<F, S> read_pair_with_message(
        std::istream &input,
        std::ostream &output,
        std::string prompt_msg,
        std::string fail_msg
    );
}

#include "read_pair_with_message_imp.h"
#include "read_pair_without_message_imp.h"
#include "read_with_message_imp.h"
#include "read_without_message_imp.h"

#endif