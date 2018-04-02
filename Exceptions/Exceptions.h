#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace TicTacToe{

    class ConvertionException : public std::exception{
    public:
        const char * what () const throw (){
            return "No suitable convertion";
        }
    };
    
    class SameFieldsException: public std::exception{
    public:
        const char * what () const throw (){
            return "Two fields are identical";
        }
    };

    class EmptyCellAssignmentException: public std::exception{
    public:
        const char * what() const throw(){
            return "You cannot set empty value on the field";
        }
    };

    class FullFieldAssignmentException: public std::exception{
    public:
        const char * what() const throw(){
            return "Field already has a winner or it is draw";
        }
    };

    class InvalidCellException: public std::exception{
    public:
        const char * what() const throw(){
            return "Coordinates of the cell are not valid";
        }
    };

    class NoStorageProvidedException: public std::exception{
        public:
        const char * what() const throw(){
            return "Storage cannot be nullpointer";
        }
    };

    class InvalidPredictionException: public std::exception{
        public:
        const char * what() const throw(){
            return "Cannot predict the move for opposite player";
        }
    };

    class InternalLogicException: public std::exception{
        public:
        const char * what() const throw(){
            return "Something in internal logic went wrong";
        }
    };

    class SamePlayersException: public std::exception{
        public:
        const char * what() const throw(){
            return "There cannot be 2 first or 2 second players simultaneously";
        }
    };

    class NoPlayerProvidedException: public std::exception{
        public:
        const char * what() const throw(){
            return "Player cannot be nullpointer";
        }
    };

    class NoFieldProvidedException: public std::exception{
        public:
        const char * what() const throw(){
            return "Field cannot be nullpointer";
        }
    };
}

#endif