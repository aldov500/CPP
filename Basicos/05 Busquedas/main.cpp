#include <iostream>
#include <iomanip>
#include <fstream>
#include "ranking.h"

using namespace std;

int main() {

    rankingList l;
    l.initialize();

    int estado = 0;

    while(estado != 5) {
        switch(estado) {
            case 0: {
                system("cls");
                int opc;

                cout<<"Discografia Completa\n\n";

                cout<<"1. Ingresar Nueva Cancion \n";
                cout<<"2. Borrar Cancion \n";
                cout<<"3. Visualizar lista \n";
                cout<<"4. Busqueda Lineal de Archivo MP3 \n";
                cout<<"5. Salida \n";
                cin >>opc;

                switch(opc) {
                    case 1:
                        estado = 1;
                        break;
                    case 2:
                        estado = 2;
                        break;
                    case 3:
                        estado = 3;
                        break;
                    case 4:
                        estado = 4;
                        break;
                    case 5:
                        estado = 5;
                        break;
                    case 6:
                        estado = 5;
                        break;

                    default:
                        estado = 0;
                        break;

                    }
                }
            break;

            case 1: {
                system("cls");
                char t[100] = {},a[100]= {},rl[100]= {},g[100]= {},m[100]= {};

                cout<<"1. Ingresar Nueva Cancion \n";

                for(int i=0; i<5; i++) {
                    system("cls");

                    cout<<"Titulo:   "<<t<<endl;
                    cout<<"Autor:    "<<a<<endl;
                    cout<<"Disquera: "<<rl<<endl;
                    cout<<"Genero:   "<<g<<endl<<endl;

                    switch(i) {
                        case 0:

                            cout<<"Ingrese el Titulo:";
                            cin.ignore();
                            cin.getline(t,100);
                            break;
                        case 1:
                            cout<<"Ingrese el Autor:";
                            cin.getline(a,100);
                            break;
                        case 2:
                            cout<<"Ingrese la Disquera:";
                            cin.getline(rl,100);
                            break;
                        case 3:
                            cout<<"Ingrese el Genero:";
                            cin.getline(g,100);
                            break;

                        }
                    }



                l.insertSong(l.getLastPos(), l.createSong(t,a,rl,g,l.getLastPos()));
                estado = 0;

                }

            break;

            case 2: {
                int opc;
                system("cls");

                cout<<"2. Borrar Cancion \n";

                for(int i=0; i<l.getLastPos()+1; i++) {
                    l.printSong(i);
                    }

                cout<<"\nIngrese posicion a borrar."<<endl;
                cin >> opc;

                l.deleteSong(opc-1);

                estado = 0;

                }
            break;

            case 3: {
                system("cls");

                cout<<"3. Visualizar lista \n";

                cout <<setw(3)<<"Num"
                     << setw(25) <<"Titulo"
                     << setw(25) <<"Autor"
                     << setw(25) <<"Disquera"
                     << setw(25) <<"Genero"
                     << setw(25) <<"File"
                     <<endl;


                for(int i=0; i<l.getLastPos()+1; i++) {
                    l.printSong(i);
                    }

                estado = 0;
                system("pause");
                }

            break;

            case 4:{
                system("cls");
                cout<<"4. Busqueda Lineal de Archivo MP3 \n";
                string temp;

                if(l.getLastPos()==-1) {
                    cout<<"Lista Vacia."<<endl;
                    system("pause");
                    estado = 0;
                    }
                else {

                    cout<<"Ingrese el Autor para obtener el nombre del archivo.";

                    cin >>temp;
                    cout<<"Nombre del Archivo: "<<l.linealSearch(temp)<<endl;
                    system("pause");
                    estado = 0;

                    }
                }

                break;


            }

        }


    return 0;
    }
