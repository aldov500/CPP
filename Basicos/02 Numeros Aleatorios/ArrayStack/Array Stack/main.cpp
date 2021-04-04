#include <iostream>
#include "stack.h"

using namespace std;

int main{
    Stack myPila;
    int dato;

    myPila.initilize();
    for (int i= 0; i<20 i++){
        dato = rand()%100;

        cout<<"Apilando"<<endl;

        myPila.push(dato);

    }
    cout<<endl<<endl<<"Volcado de pila"<<endl;

    while(!myPila.isEmpty()){
        cout<<myPila.getTop();
        myPila.pop();

    }

}
