#ifndef RANKINGEXCEPTION_H_INCLUDED
#define RANKINGEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

class ListException: public std::exception{
private:
    std::string msg;

public:
    explicit ListException(const char* message):msg(message){}
    explicit ListException(const std::string message):msg(message){}

    virtual ~ListException() throw() {}

    virtual const char* what() const throw(){
        return msg.c_str();

    }
};


#endif // RANKINGEXCEPTION_H_INCLUDED
