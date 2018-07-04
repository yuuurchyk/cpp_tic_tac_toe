#ifndef OPTION_H_
#define OPTION_H_

#include <string>

namespace TicTacToe{
    class Option{
    public:
        Option(
            const std::string &shortcut,
            const std::string &name,
            const std::string &explanation=""
        );

        const std::string
            shortcut{},
            name{},
            explanation{};
        
        bool operator==(const Option& rhs);
    };

    extern const Option
        kYes,
        kNo;
};

#endif