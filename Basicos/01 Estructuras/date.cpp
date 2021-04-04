#include "date.h"

/*Definicion de los metodos*/
int Date::getYear()
{
return year;

}

int Date::getMonth()
{
return month;
}

int Date::getDay()
{
return day;
}

void Date::setYear(const int& y)
{
    year = y;
}

void Date::setMonth(const int& m)
{
    month = m;
}

void Date::setDay(const int& d)
{
    day = d;
}
