#ifndef NODEEXCEPTION_H_INCLUDED
#define NODEEXCEPTION_H_INCLUDED


class NodeException : public std::exception {
    protected:
        std::string msg;

    public:
        explicit NodeException(const char* message) : msg(message) { }
        explicit NodeException(const std::string& message) : msg(message) { }

        virtual ~NodeException() throw () { }
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

#endif // NODEEXCEPTION_H_INCLUDED
