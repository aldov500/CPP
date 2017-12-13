/*  Clase Matriz
    Aldo Vargas
    213495653
file: matrix.cpp*/

#include "matrix.h"
#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <iomanip>
using namespace std;


void Matrix::setN(){
    system("cls");
    int x = 0;

    while(x == 0){
        cout<<"Ingresa tamanio de Matriz [3 - 10]: "<<endl;
        cin >> x;


        if(x>=3 && x<=10){
            n = x;

        } else{
            cout<<"Error de limites"<<endl;

            system("pause");
            system("cls");


        }
    }
}

int Matrix::getN(){
    return n;
}

void Matrix::createMatrix(const int& n){
    /*Declaracion de matrices*/
    float origMatrix[n][n];
    float sumaMatrix[n][n];
    float multMatrix[n][n];
    /*Declaracion para aleatorio flotante de -100.00 a 100.00*/
    float random;
    int _2decimals;
    srand(time(NULL));

    system("cls");

    /*Generacion de matrices*/
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            /*Generacion aleatorio entre -100.00 hasta 100.00*/
            random = ((static_cast <float> (rand())) /( static_cast <float> (RAND_MAX/(200.00))))-100.00;
            _2decimals = (random*100);
            random = (_2decimals*1.0)/100;

            origMatrix[x][y] = random;
            sumaMatrix[x][y] = (origMatrix[x][y] + origMatrix[x][y]);

        }
    }

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){
            multMatrix[i][j] = 0;

  		for (int k = 0; k < n; k++){
  			multMatrix[i][j]=multMatrix[i][j]+(origMatrix[i][k]*origMatrix[k][j]);

  		}
  	}
  }

    /*Impresion de matrices*/
    cout<<endl<<" Matriz generada: "<<endl<<endl;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            cout<<"|"<<setw(6)<<origMatrix[x][y]<<" |";

            if(y==n-1){
              cout<<endl;
            }
       }
    }

    cout<<endl<<" Matriz Sumatoria: "<<endl<<endl;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            cout<<"|"<<setw(8)<<sumaMatrix[x][y]<<" |";

            if(y==n-1){
              cout<<" "<<endl;

            }
       }
    }

    cout<<endl<<" Matriz Multiplicacion: "<<endl<<endl;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            cout<<"|"<<setw(10)<<multMatrix[x][y]<<" |";

            if(y==n-1){
              cout<<endl;

            }
       }
    }
    cout<<endl;

}
