#include <iostream>
#include "list.h"

using namespace std;

int main(){
List myLista;

myLista.initialize();
int dato;

for(int i= 0; i<50; i++){
    dato = rand()&100;

    cout<<"Insertando: "<<dato<<endl;
    myLista.insertData(myLista.lastPos(),dato);

}
cout<<endl;
myLista.deleteData(100);
cout<<"El contenido de la lista es: "<<endl;
myLista.print();
}

