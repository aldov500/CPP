#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date{
/*Interfaz*/
private:
/*Atributos*/
int year, month, day;

public:
/*Metodos*/
int getYear();
int getMonth();
int getDay();

void setYear(const int&);
void setMonth(const int&);
void setDay(const int&);

};
#endif // DATE_H_INCLUDED
