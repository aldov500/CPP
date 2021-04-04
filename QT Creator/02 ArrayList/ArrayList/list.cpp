#include "list.h"

void List::initialize() {
    last = -1;
    }

bool List::isEmpy() {
    return last == -1;
    }

bool List::isFull() {
    return last == 499;
    }

void List::insertData(const int& p, const int& e) {
    if(isFull()) {
        throw ListException("Desbordamiento de datos.");
        }
    else if(p< -1 || (p>last)) {
        throw ListException("Posicion invalida");
        }



    int i = last;

    while(i>p) {
        data[i+1] = data[i];
        i++;
        }
    data[p+1] = e;
    last++;

    }

void List::deleteData(const int& p) {
    if(isFull()) {
        throw ListException("Insuficiencia de datos.");
        }
    else if(p< -1 || (p>last)) {
        throw ListException("Posicion invalida");
        }
    int i = p;
    while(i<last) {
        data[i] = data[i+1];
        i++;
        }
    last--;
    }

int List::firstPos() {
    if(isEmpy()) {
        return -1;
        }
    return 0;
    }

int List::lastPos() {
    return last;
    }

int List::prevPos(const int& p) {
    if(isEmpy() || p<1 or p>last) {
        return -1;
        }
    return p-1;
    }

int List::nextPos(const int& p) {
    if(isEmpy() || p<0 || p>(last-1)) {
        return -1;
        }
    return p + 1;

    }

int List::findData(const int&) {
    //pendiente
    }

int List::retrieve(const int& p) {
    if(isFull()) {
        throw ListException("Insuficiencia de datos.");
        }
    else if(p< -1 || (p>last)) {
        throw ListException("Posicion invalida");
        }
    return data[p];
    }

void List::sortData() {
    //Pendiente

    }

void List::print() {
    int i = 0;
    while(i<=last) {
        std::cout<<data[i]<<std::endl;
        i++;
        }

    }

void List::deleteAll() {
    last = -1;
    }
