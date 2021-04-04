#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED

class Nodo {
  public:

   Nodo(const int dat, Nodo *pad=NULL, Nodo *izq=NULL, Nodo *der=NULL) :
     dato(dat), padre(pad), izquierdo(izq), derecho(der), FE(0) {}

   int dato;
   int FE;

   Nodo *izquierdo;
   Nodo *derecho;
   Nodo *padre;
   friend class AVL;
};


#endif // AVLNODE_H_INCLUDED
