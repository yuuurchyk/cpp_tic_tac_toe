#include <set>
#include <string>
#include <algorithm>

#include "Select.h"
#include "../Exceptions/SelectExceptions.h"

using namespace TicTacToe;

Select::Select(const std::initializer_list<Option> &lst){
    if(lst.size() == 0)
        throw SelectInitError();
    
    std::set<std::string>
        shortcuts,
        names;
    
    options.reserve(lst.size());
    
    for(const auto &it: lst){
        options.push_back(it);
        shortcuts.insert(it.shortcut);
        names.insert(it.name);
    }

    if(shortcuts.size() < lst.size() || names.size() < lst.size())
        throw SelectInitError();
}

Select::iterator Select::begin(){ return options.begin(); }
Select::iterator Select::end(){ return options.end(); }

Select::const_iterator Select::begin() const { return options.cbegin(); }
Select::const_iterator Select::end() const { return options.cend(); }
