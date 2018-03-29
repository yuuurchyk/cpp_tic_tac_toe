#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace Exceptions{

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
}

#endif