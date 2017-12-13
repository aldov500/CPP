/*  Header Clase Matriz
    Aldo Vargas
    213495653
file: matrix.h*/

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class Matrix{
private:
    int n;

public:
    /*Imprime las matrices*/
    void createMatrix(const int&);
    /*Establece n*/
    void setN();
    int  getN();

};

#endif // MATRIX_H_INCLUDED
