#include <iostream>
#include <algorithm>
#include <cctype>

#include "Text.h"
#include "../Exceptions/TextExceptions.h"

using namespace TicTacToe;

namespace{
    bool isOkChar(const char &c){
        return isalpha(c) || isdigit(c) || ispunct(c) || (c == ' ');
    }
}

std::string TicTacToe::normalize(const std::string &str){
    std::string res{};
    std::copy_if(str.cbegin(), str.cend(), std::back_inserter(res), isOkChar);
    return res;
}

TextEntry::TextEntry(
    const TextType &textType,
    const std::string &textStr
):
    textType(textType),
    textStr(normalize(textStr))
{
    if(textStr.empty())
        throw TextEntryError();
}

Text::Text(){}
Text::Text(const std::initializer_list<TextEntry> &lst){
    for(const auto &it: lst)
        push_back(it);
}

Text::iterator Text::begin(){
    return lst.begin();
}
Text::iterator Text::end(){
    return lst.end();
}

Text::const_iterator Text::begin() const{
    return lst.cbegin();
}
Text::const_iterator Text::end() const{
    return lst.cend();
}

void Text::push_back(const TextEntry &textEntry){
    lst.push_back(textEntry);
}
void Text::push_front(const TextEntry &textEntry){
    lst.push_front(textEntry);
}

void Text::pop_back(){
    lst.pop_back();
}
void Text::pop_front(){
    lst.pop_front();
}

size_t Text::height() const{
    return lst.size();
}

size_t Text::maxWidth() const{
    size_t res{0};
    for(const auto &it: lst)
        res = std::max(res, it.textStr.size());
    return res;
}
