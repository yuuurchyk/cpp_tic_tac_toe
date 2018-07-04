#ifndef TEXT_H_
#define TEXT_H_

#include <utility>
#include <string>
#include <initializer_list>
#include <list>

namespace TicTacToe{
    std::string normalize(const std::string &str);

    enum class TextType{
        Regular, Success, Error
    };

    class TextEntry{
    public:
        TextEntry(
            const TextType &textType,
            const std::string &textStr
        );

        const TextType textType;
        const std::string textStr;
    };

    class Text{
    public:
        Text(const std::initializer_list<TextEntry> &lst);
        Text();

        typedef std::list<TextEntry>::iterator iterator;
        typedef std::list<TextEntry>::const_iterator const_iterator;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        void push_back(const TextEntry &textEntry);
        void push_front(const TextEntry &textEntry);

        void pop_back();
        void pop_front();

        size_t height() const;
        size_t maxWidth() const;
    private:
        std::list<TextEntry> lst{};
    };
}

#endif