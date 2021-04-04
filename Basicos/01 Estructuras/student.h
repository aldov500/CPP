#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include "name.h"
#include "date.h"

class Student{
private:
    std::string code;
    std::string career;
    Name name;
    Date dateOfBird;
    Date dateOfRegistry;
    float grade;

public:
    std::string getCode();
    std::string getCareer();
    Name getName();
    Date getDateOfBird();
    Date getDateOfRegistry();
    float getGrade();

    void setCode(const std::string&);
    void setCareer(const std::string&);
    void setName(const Name&);
    void setDateOfBird(const Date&);
    void setDateOfRegistry(const Date&);
    void setGrade(const float&);

};

#endif // STUDENT_H_INCLUDED
