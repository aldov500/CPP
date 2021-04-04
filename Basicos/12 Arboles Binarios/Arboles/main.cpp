#include <iostream>
#include<stdlib.h>
#include<time.h>

#include "binaryTree.h"

using namespace std;

void Mostrar(int d) {
    cout << d << "|";
    }

int main() {
    int maxV = 0;
    binaryTree t;

    int opc = 0;

    while(opc != 5) {
        switch(opc) {
            case 0:
                cout<< "Ingrese la cantidad de Valores a Generar en el Arbol Binario: ";
                cin >> maxV;
                int valor;
                for(int i=0; i<=maxV-1; i++) {
                    cout<<"Inserte un valor: "<<endl;
                    cin >> valor;
                    t.treeInsert(valor);
                    }
                system("pause");
                system("cls");
                opc++;
                break;

            case 1:
                cout<< "Propiedades del Arbol" <<endl<<endl;

                cout<< "Altura: " << t.treeHeight() <<endl;
                cout<< "Nodos:  " << t.nodeCounter() <<endl<<endl;

                system("pause");
                system("cls");
                opc++;

                break;

            case 2:
                cout<<"Ordenamiento de Datos: "<<endl;

                cout<< "Pre Order: "<<endl;
                t.treePreOrder(Mostrar);
                cout<<endl<<endl;

                cout<< "In Order: "<<endl;
                t.treeInOrder(Mostrar);
                cout<<endl<<endl;

                cout<< "Post Order: "<<endl;
                t.treePostOrder(Mostrar);
                cout<<endl<<endl;

                system("pause");
                system("cls");
                opc++;


                break;

            case 3:
                cout<<"Borrado de la Mitad de los elementos: "<<endl;
                for(int i=maxV/2; i<maxV; i++) {
                    t.treeDelete(i);
                    }

                system("pause");
                system("cls");
                opc++;

                break;

            case 4:
                cout<<"Ordenamiento de Datos: "<<endl;

                cout<< "Pre Order: "<<endl;
                t.treePreOrder(Mostrar);
                cout<<endl<<endl;

                cout<< "In Order: "<<endl;
                t.treeInOrder(Mostrar);
                cout<<endl<<endl;

                cout<< "Post Order: "<<endl;
                t.treePostOrder(Mostrar);
                cout<<endl<<endl;

                system("pause");
                system("cls");
                opc++;
                break;



            }

        }
    return 0;
    }
