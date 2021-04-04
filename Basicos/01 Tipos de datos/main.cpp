/* Program Principal datos primitivos y estructurados
   Aldo Vargas
   213495653
file: main.cpp*/

#include <iostream>
#include "dataTypes.h"
#include "matrix.h"

using namespace std;



int main(){
char menuOpt = 's';

DataTypes dty;
Matrix mtx;

while(menuOpt){

    cout<< "Tipos de datos PRIMITIVO | ESTRUCTURADO " <<endl<<endl;
    cout<< "a) Tamanio y rango de tipos de Datos Primitivos" <<endl;
    cout<< "b) Ejemplo de uso de tipo de Dato Estructurado" <<endl;
    cout<< "c) Salir" <<endl<<endl ;
    cout<< "Seleccione una opcion: "; cin >> menuOpt;
    system("cls");

    if(menuOpt == 'a' || menuOpt == 'A'){
        cout<< "Tamanio y rango de tipos de Datos Primitivos" <<endl<<endl;
        for(int i=0; i<8; i++){
                dty.setValues(i);
                dty.getValues(i);
        }
        system("pause");
        system("cls");

    } else if(menuOpt == 'b' || menuOpt == 'B'){
        cout<< "Ejemplo de uso de tipo de Dato Estructurado" <<endl<<endl;
        mtx.setN();
        mtx.createMatrix(mtx.getN());
        system("pause");
        system("cls");

    } else if(menuOpt == 'c' || menuOpt == 'C'){
        cout << "Saliendo del programa..." <<endl;
        return 0;
    }
    else{
        cout << "Opcion incorrecta" <<endl;
        system("pause");
        system("cls");

    }

}

return 0;
}

