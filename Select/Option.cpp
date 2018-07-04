#include <algorithm>
#include <cctype>

#include "Option.h"
#include "../Exceptions/SelectExceptions.h"

using namespace TicTacToe;

Option::Option(
    const std::string &shortcut,
    const std::string &name,
    const std::string &explanation
):
    shortcut(shortcut),
    name(name),
    explanation(explanation)
{
    if(name.empty())
        throw OptionInitError();
    if(std::count_if(shortcut.begin(), shortcut.end(), isspace) != 0 || shortcut.empty())
        throw OptionInitError();
}

bool Option::operator==(const Option &rhs){
    return
        shortcut == rhs.shortcut &&
        name == rhs.name;
}

const Option
    TicTacToe::kYes{"y", "Yes", ""},
    TicTacToe::kNo{"n", "No", ""};
