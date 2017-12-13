/*  Clase Tipos de Datos
    Aldo Vargas
    213495653
file: dataTypes.cpp*/
#include "dataTypes.h"
#include   <iostream>
#include    <iomanip>
#include     <math.h>
using namespace std;

void DataTypes::getValues(const int& s){
    /*Imprime la tabla de tipos de datos*/
    if(s == 0){
        cout<<setw(16)<<"Tipo de Dato"<<setw(7)<<"Bits"<<setw(14)<<"Valor Minimo"<<setw(14)<<"Valor Maximo"<<endl;
        cout<<setw(16)<<dataType<<setw(7)<<bits<<setw(14)<<minValue<<setw(14)<<maxValue<<endl;
    }
    else{
        cout<<setw(16)<<dataType<<setw(7)<<bits<<setw(14)<<minValue<<setw(14)<<maxValue<<endl;
    }
}

void DataTypes::setValues(const int& s){
    /*Characters*/
    if(s == 0){
        dataType = "Unsigned Char";             //Asigna el tipo de dato
        bits = sizeof(unsigned char) * 8;       //Obtiene su tamaño en bits
        maxValue = -1 + (pow(2,bits));          //Calculo de valor maximo
        minValue =  0;                          //Dado que es unsigned el min es cero

    }else if(s == 1){
        dataType = "Signed Char";
        bits = sizeof(signed char) * 8;
        maxValue = -1 + (pow(2,bits)/2);        //El valor maximo es la mitad del rango positivo
        minValue =  0 - (pow(2,bits)/2);        //y la mitad negativa será el minimo

    }
    /*Integers*/
    else if(s == 2){
        dataType = "Unsigned Short";
        bits = sizeof(unsigned short int) * 8;
        maxValue = -1 + (pow(2,bits));
        minValue =  0;

    }else if(s == 3){
        dataType = "Signed Short";
        bits = sizeof(signed short int) * 8;
        maxValue = -1 + (pow(2,bits)/2);
        minValue =  0 - (pow(2,bits)/2);
    }
    /*Longs*/
    else if(s == 4){
        dataType = "Unsigned Long";
        bits = sizeof(unsigned long) * 8;
        maxValue = -1 + (pow(2,bits));
        minValue =  0;

    }else if(s == 5){
        dataType = "Signed Long";
        bits = sizeof(signed long) * 8;
        maxValue = -1 + (pow(2,bits)/2);
        minValue =  0 - (pow(2,bits)/2);

    }
    /*Floats*/
    else if(s == 6){
        dataType = "Float";
        bits = sizeof(float) * 8;
        maxValue = -1 + (pow(2,bits));
        minValue =  0;

    }else if(s == 7){
        dataType = "Double";
        bits = sizeof(double) * 8;
        maxValue = -1 + (pow(2,bits));
        minValue =  0;

    }


}
