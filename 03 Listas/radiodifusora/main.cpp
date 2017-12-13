#include <iostream>
#include "ranking.h"

using namespace std;

int main() {
    rankingList l;
    l.initialize();

    int estado = 0;

    while(estado != 3) {
        switch(estado) {
            case 0: {
                system("cls");
                int opc;

                /*Impresion de la tabla*/
                cout<<setw(20)<<"Ranking Canciones\n";
                for(int i=0; i<l.getLastPos()+1; i++) {
                    l.printSong(i);
                    }

                cout<<"  \nSeleccione una opcion\n";
                cout<<"1) Ingresar Nueva Cancion.\n";
                cout<<"2) Borrar una cancion.\n";
                cout<<"3) Salir\n";
                cin >>opc;

                if(opc == 1) estado = 1;
                if(opc == 2) estado = 2;
                if(opc == 3) estado = 3;
                }
            break;

            case 1: {
                system("cls");
                string t,a,rl,g;

                for(int i=0; i<5; i++) {
                    system("cls");
                    cout<<setw(30)<<"Ranking Canciones\n";

                    for(int i=0; i<l.getLastPos()+1; i++) {
                        l.printSong(i);
                        }


                    cout<<"Titulo:   "<<t<<endl;
                    cout<<"Autor:    "<<a<<endl;
                    cout<<"Disquera: "<<rl<<endl;
                    cout<<"Genero:   "<<g<<endl<<endl;

                    switch(i) {
                        case 0:
                            cout<<"Ingrese el Titulo:";
                            cin >> t;
                            break;
                        case 1:

                            cout<<"Ingrese el Autor:";
                            cin >> a;
                            break;
                        case 2:

                            cout<<"Ingrese la Disquera:";
                            cin >> rl;
                            break;
                        case 3:

                            cout<<"Ingrese el Genero:";
                            cin >>g;
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

                cout<<setw(30)<<"Ranking Canciones\n";
                for(int i=0; i<l.getLastPos()+1; i++) {
                    l.printSong(i);
                    }

                cout<<"Borrado de Cancion."<<endl;
                cout<<"Ingrese posicion a borrar."<<endl;
                cin >> opc;

                l.deleteSong(opc-1);

                estado = 0;

                }
            break;


            }

        }
    return 0;
    }
