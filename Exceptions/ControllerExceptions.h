#ifndef CONTROLLER_EXCEPTOINS_H_
#define CONTROLLER_EXCEPTOINS_H_

#include <exception>
#include "CommonExceptions.h"

namespace TicTacToe{
    class ControllerError: public TicTacToeError{
    public:
        const char * what() const noexcept{
            return "Something went wrong while operating controller";
        }
    };

    class QuitError: public ControllerError{
    public:
        const char * what() const noexcept{
            return "User wants to quit";
        }
    };

    class RestartError: public ControllerError{
    public:
        const char * what() const noexcept{
            return "User wants to restart";
        }
    };

    class ControllerGetError: public ControllerError{
    public:
        const char * what() const noexcept{
            return "Cannot initialize controller after destruction";
        }
    };

    class GuiControllerError: public ControllerError{
    public:
        const char * what() const noexcept{
            return "Something went wrong while operating GuiController";
        }
    };

    class GuiControllerTerminalColorError: public GuiControllerError{
    public:
        const char * what() const noexcept{
            return "You terminal does not support colors";
        }
    };

    class GuiControllerTerminalSizeError: public GuiControllerError{
    public:
        const char * what() const noexcept{
            return "Your terminal is too small. Try to make if full screen";
        }
    };
}

#endif