#include "student.h"
using namespace std;

string Student::getCode()
{
    return code;
}

string Student::getCareer()
{
    return career;
}

Name Student::getName()
{
    return name;
}

Date Student::getDateOfBird()
{
    return dateOfBird;
}

Date Student::getDateOfRegistry()
{
    return dateOfRegistry;
}

float Student::getGrade()
{
    return grade;
}

void Student::setCode(const string& c)
{
    code = c;
}

void Student::setCareer(const string& c)
{
    career = c;
}

void Student::setName(const Name& n)
{
    name = n;
}

void Student::setDateOfBird(const Date& d)
{
    dateOfBird = d;
}

void Student::setDateOfRegistry(const Date& d)
{
    dateOfRegistry = d;
}

void Student::setGrade(const float& g)
{
    grade = g;
}

