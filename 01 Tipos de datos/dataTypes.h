/*  Header Tipos de Datos
    Aldo Vargas
    213495653
file: dataTypes.h*/
#ifndef DATATYPES_H_INCLUDED
#define DATATYPES_H_INCLUDED

#include <string>

class DataTypes{

private:
    std::string dataType;
    float minValue, maxValue;
    int bits;

public:
    /*Imprime la tabla*/
    void getValues(const int&);
    /*Calcula la tabla*/
    void setValues(const int&);

};


#endif // DATATYPES_H_INCLUDED
