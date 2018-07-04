#ifndef ABSTRACT_CONTROLLER_H_
#define ABSTRACT_CONTROLLER_H_

#include <string>
#include <utility>
#include <cstddef>

#include "../Field/Field.h"
#include "../Text/Text.h"
#include "../Player/AbstractPlayer.h"
#include "../Select/Select.h"

namespace TicTacToe{
    class AbstractController{
    public:
        AbstractController(Field const * field);

        static const std::string
            kQuitStr,
            kRestartStr;

        virtual void update();
        virtual void update(Field const * field);
        virtual std::string getRaw(const Text &text) = 0;

        std::pair<size_t, size_t> getCoordinates(const Text &text);
        Option select(const std::string &message, const Select &select);
        Option select(const Text &text, const Select &select);
        std::string getPlayerName(const Text &text);

        virtual ~AbstractController() = default;
    protected:
        Field const * field{nullptr};
        static const Text kInfoText;
    private:
        bool checkQuit(const std::string &str);
        bool checkRestart(const std::string &str);
    };
}

#endif