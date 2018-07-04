#ifndef GUI_CONTROLLER_H_
#define GUI_CONTROLLER_H_

#include <cstddef>

#include "AbstractController.h"
#include "StaticInfoWindow.h"
#include "ConsoleWindow.h"
#include "FieldWindow.h"
#include "../Field/Field.h"

namespace TicTacToe{
    extern const std::string kGuiControllerToken;

    class GuiController: public AbstractController{
    public:
        static GuiController *get(Field const * field);

        void update();
        void update(Field const * field);
        std::string getRaw(const Text &text);

        GuiController(const GuiController&) = delete;
        GuiController& operator=(const GuiController&) = delete;

        virtual ~GuiController();
    private:
        static const size_t
            kMinHeight,
            kMinWidth;

        static bool wasDestroyed;
        static GuiController *controller;

        GuiController(Field const * field);

        StaticInfoWindow *staticInfoWindow{nullptr};
        FieldWindow *fieldWindow{nullptr};
        ConsoleWindow *consoleWindow{nullptr};
    };
}

#endif