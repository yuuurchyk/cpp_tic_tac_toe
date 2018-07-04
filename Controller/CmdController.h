#ifndef CMD_CONTROLLER_H_
#define CMD_CONTROLLER_H_

#include <string>

#include "AbstractController.h"
#include "../Field/Field.h"
#include "../Text/Text.h"

namespace TicTacToe{
    extern const std::string kCmdControllerToken;

    class CmdController: public AbstractController{
    public:
        static CmdController *get(Field const * field);

        void update();
        void update(Field const * newField);
        std::string getRaw(const Text &text);

        CmdController(const CmdController&) = delete;
        CmdController& operator=(const CmdController&) = delete;

        virtual ~CmdController();
    private:
        static bool wasDestroyed;
        static CmdController *controller;

        CmdController(Field const * field);

        void clear();
        void write(const Text &text);
    };
}

#endif