#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include "listException.h"

/*La plantilla y e template van en cada metodo y atributo que se use en la clase*/
template <class T> class List{
private:
    int data[500];
    int last;

public:
    void initialize();
    bool isEmpy();
    bool isFull();

    void insertData(const int&,const int&);
    void deleteData(const int&);

    int firstPos();
    int lastPos();
    int prevPos(const int&);
    int nextPos(const int&);
    int findData(const int&);

    int retrieve(const int&);
    void sortData();
    void print();
    void deleteAll();

};



#endif // LIST_H_INCLUDED
