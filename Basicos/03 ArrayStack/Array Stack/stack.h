#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <exception>
#include <string>

class StackException: public std::exception {
    private:
        std::string msg;

    public:
        explicit StackException(const char* message):msg(message) {}
        explicit StackException(const std::string message):msg(message) {}

        virtual ~StackException() throw() {}

        virtual const char* what() const throw() {
            return msg.c_str();

            }
    };


template <class T, int ARRAYSIZE = 1024> class Stack {
    private:
        T data[ARRAYSIZE];
        int top;


    public:
        void initialize();
        bool isEmpty();
        bool isFull();
        void push(const&);

        T pop();
        T getTop();

};

template <class T, int ARRAYSIZE>
void Stack<T,ARRAYSIZE>::initialize()
{
        top = -1;
}

template <class T, int ARRAYSIZE>
bool Stack<T,ARRAYSIZE>::isEmpty()
{

}

template <class T, int ARRAYSIZE>
bool Stack<T,ARRAYSIZE>::isFull()
{

}


template <class T, int ARRAYSIZE>
void Stack<T,ARRAYSIZE>::push(const &e)
{
    if(isFull()){
        throw StackException("Desbordamiento de datos en el push");
    }

    data[++top] = e;
}

template <class T, int ARRAYSIZE>
T Stack<T,ARRAYSIZE>::pop()
{
        if(isEmpty()){
            throw StackException("Insuficiencia de datos haciendo pop");

        }
        top--;
}

template <class T, int ARRAYSIZE>
T Stack<T,ARRAYSIZE>::getTop()
{
        if(isEmpty()){
            throw StackException("Insificiencia de datos en el top");
        }
        return data[top];
}



#endif // STACK_H_INCLUDED
