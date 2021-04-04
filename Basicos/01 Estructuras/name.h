#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <string>
class Name{
private:
    std::string last;
    std::string first;

public:
    std::string getLast();
    std::string getFirst();

    void setLast(const std::string&);
    void setFirst(const std::string&);
};




#endif // NAME_H_INCLUDED
