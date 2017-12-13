#include <iostream>
#include <iomanip>
#include <fstream>
#include "linkedList.h"

using namespace std;

void FileHandlerRecover(LinkedList& l) {
    ifstream lectura;

    lectura.open("canciones.txt",ios::out | ios::in);

    string indice;
    string t, a, rl, g;

    if(lectura.is_open()) {

        int i=-1;

        std::getline(lectura, indice);

        while(!lectura.eof()) {

            std::getline(lectura, t);
            std::getline(lectura, a);
            std::getline(lectura, rl);
            std::getline(lectura, g);

            Song temp;

            temp.setTitle(t);
            temp.setAuthor(a);
            temp.setRecordL(rl);
            temp.setGenre(g);
            temp.setMP3(a,t);

            l.insertNode(nullptr, temp);

            std::getline(lectura, indice);
            }
        }


    }

void FileHandlerInsert(char t[100] = {}, char a[100]= {}, char rl[100]= {}, char g[100]= {}) {
    ofstream escritura;
    escritura.open("canciones.txt",ios::out | ios::app);

    char i = '-';
    if(escritura.is_open()) {
        escritura << i<<endl;
        escritura << t << endl;
        escritura << a << endl;
        escritura << rl << endl;
        escritura << g << endl;

        }

    escritura.close();
    }

void FileHandlerDelete(string data) {
    ofstream aux;
    ifstream lectura;

    string indice,t, a, rl, g;

    aux.open("auxiliar.txt",ios::out);
    lectura.open("canciones.txt",ios::in);

    if(aux.is_open() && lectura.is_open()) {
        int i=0;

        while(!lectura.eof()) {

            std::getline(lectura, indice);
            std::getline(lectura, t);
            std::getline(lectura, a);
            std::getline(lectura, rl);
            std::getline(lectura, g);

            if(data != t ) {

                aux << i <<endl;
                aux << t << endl;
                aux << a << endl;
                aux << rl << endl;
                aux << g << endl;


                i++;
                }

            }

        }
    else {
        cout<<"Error de Borrado."<<endl;
        system("pause");
        }


    aux.close();
    lectura.close();
    remove("canciones.txt");
    rename("auxiliar.txt","canciones.txt");
    }

int main() {

    LinkedList l;
    FileHandlerRecover(l);
    int estado = 0;

    while(estado != 6) {

        switch(estado) {

            case 0: {
                system("cls");
                int opc;
                cout<<"-- Base de Datos de Canciones --\n\n";
                cout<<"1. Ingresar Nueva Cancion \n";
                cout<<"2. Borrar Cancion (PENDIENTE)\n";
                cout<<"3. Ordenar Lista \n";
                cout<<"4. Visualizar lista \n";
                cout<<"5. Busqueda Lineal de Archivo MP3 \n";
                cout<<"6. Salida "<<endl;
                cin >> estado;

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


                Song newSong = l.createSong(t,a,rl,g);

                l.insertNode(l.getLast(), newSong);

                FileHandlerInsert(t,a,rl,g);

                estado = 0;

                }
            break;

            case 2: {
                system("cls");
                char buscar[100];

                cout<<"2. Borrar Cancion \n\n";
                cout<<"Ingrese el nombre de la cancion: "<<endl;
                cin.ignore();
                cin.getline(buscar,100);
                Node* aux;

                cout<< l.locateByTitle(buscar)->getData().getSongInfo();

                aux = l.locateByTitle(buscar);


                l.deleteNode(aux);

                FileHandlerDelete(buscar);

                system("pause");
                estado = 0;

                }
            break;

            case 3: {
                system("cls");
                cout<<"3. Ordenar Lista  \n";

                l.sortData();
                cout<<"HECHO.\n";
                system("pause");
                estado = 0;
                }
            break;

            case 4: {
                system("cls");
                cout<<"4. Visualizar lista \n";
                l.printList();
                system("pause");
                estado = 0;

                }
            break;

            case 5: {
                system("cls");
                string printed;
                char b[100] = {};
                cout<<"5. Busqueda Lineal de Archivo MP3 \n";
                cin.ignore();
                cin.getline(b,100);

                Node* aux;
                printed = l.locateByTitle(b)->getData().getSongInfo();
                cout<< printed;

                system("pause");
                estado = 0;


                }
            break;

            default:
                estado = 0;
                break;


            }


        }


    return 0;
    }
