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
    
    class SameFieldsExceptions: public std::exception{
    public:
        const char * what () const throw (){
            return "Two fields are identical";
        }
    };

    class EmptyCellAssignment: public std::exception{
    public:
        const char * what() const throw(){
            return "You cannot set empty value on the field";
        }
    };

    class FullFieldAssignment: public std::exception{
    public:
        const char * what() const throw(){
            return "Field already has a winner or it is draw";
        }
    }
}

#endif