#include <iostream>
using namespace std;

class AvlTree;


class AvlTreeNode {
  public:
  
   AvlTreeNode(const int dat, AvlTreeNode *pad=nullptr, AvlTreeNode *izq=nullptr, AvlTreeNode *der=nullptr) :
     data(dat), father(pad), left(izq), right(der), FE(0) {}
  
   int data;
   int FE;

   AvlTreeNode *left;
   AvlTreeNode *right;
   AvlTreeNode *father;
   friend class AvlTree;
};

class AvlTree {
  private:

   enum {left, right};
   int contador;
   int altura;

   AvlTreeNode *raiz;
   AvlTreeNode *actual;

   void Equilibrar(AvlTreeNode *AvlTreeNode, int, bool);

   void RSI(AvlTreeNode* AvlTreeNode);
   void RSD(AvlTreeNode* AvlTreeNode);
   void RDI(AvlTreeNode* AvlTreeNode);
   void RDD(AvlTreeNode* AvlTreeNode);

   void Podar(AvlTreeNode* &);
   void auxContador(AvlTreeNode*);
   void auxAltura(AvlTreeNode*, int);
   
  public:

   AvlTree() : raiz(nullptr), actual(nullptr) {}
   ~AvlTree() { Podar(raiz); }

   void avlInsert(const int dat);
   void Borrar(const int dat);
   bool Buscar(const int dat);
   bool isEmpty(AvlTreeNode *r) { return r==nullptr; }
   bool EsHoja(AvlTreeNode *r) { return !r->right && !r->left; }
   
   const int NumeroAvlTreeNodes();
   const int AlturaArbol();
   
   int Altura(const int dat);
   int &ValorActual() { return actual->data; }
   void Raiz() { actual = raiz; }
   
   void InOrden(void (*func)(int&, int) , AvlTreeNode *AvlTreeNode=nullptr, bool r=true);
   void PreOrden(void (*func)(int&, int) , AvlTreeNode *AvlTreeNode=nullptr, bool r=true);
   void PostOrden(void (*func)(int&, int) , AvlTreeNode *AvlTreeNode=nullptr, bool r=true);
  
};


void AvlTree::Podar(AvlTreeNode* &AvlTreeNode)
{
   if(AvlTreeNode) {
      Podar(AvlTreeNode->left); 
      Podar(AvlTreeNode->right);
      delete AvlTreeNode;       
      AvlTreeNode = nullptr;
   }
}

void AvlTree::avlInsert(const int dat)
{
   AvlTreeNode *father = nullptr;

   cout << "avlInsert: " << dat << endl;
   actual = raiz;

   while(!isEmpty(actual) && dat != actual->data) {
      father = actual;
      if(dat > actual->data) actual = actual->right;
      else if(dat < actual->data) actual = actual->left;
   }


   if(!isEmpty(actual)) return;
   
   if(isEmpty(father)) raiz = new AvlTreeNode(dat);
   else if(dat < father->data) {
      father->left = new AvlTreeNode(dat, father);
      Equilibrar(father, left, true);
   }
   
   else if(dat > father->data) {
      father->right = new AvlTreeNode(dat, father);
      Equilibrar(father, right, true);
   }
}


void AvlTree::Equilibrar(AvlTreeNode *AvlTreeNode, int rama, bool nuevo)
{
   bool salir = false;

   while(AvlTreeNode && !salir) {
      if(nuevo)
         if(rama == left) AvlTreeNode->FE--; 
         else                  AvlTreeNode->FE++;
      else
         if(rama == left) AvlTreeNode->FE++; 
         else                  AvlTreeNode->FE--;
      if(AvlTreeNode->FE == 0) salir = true; 
                                      
                                      
      else if(AvlTreeNode->FE == -2) { 
         if(AvlTreeNode->left->FE == 1) RDD(AvlTreeNode); 
         else RSD(AvlTreeNode);                         
         salir = true;
      }
      else if(AvlTreeNode->FE == 2) {  
         if(AvlTreeNode->right->FE == -1) RDI(AvlTreeNode);
         else RSI(AvlTreeNode);                     
         salir = true;
      }
      if(AvlTreeNode->father)
         if(AvlTreeNode->father->right == AvlTreeNode) rama = right; else rama = left;
      AvlTreeNode = AvlTreeNode->father; 
   }
}

void AvlTree::RDD(AvlTreeNode* nodo)
{
   cout << "RDD" << endl;
   AvlTreeNode *father = nodo->father;
   AvlTreeNode *P = nodo;
   AvlTreeNode *Q = P->left;
   AvlTreeNode *R = Q->right;
   AvlTreeNode *B = R->left;
   AvlTreeNode *C = R->right;

   if(father)
     if(father->right == nodo) father->right = R;
     else father->left = R;
   else raiz = R;


   Q->right = B;
   P->left = C;
   R->left = Q;
   R->right = P;


   R->father = father;
   P->father = Q->father = R;
   if(B) B->father = Q;
   if(C) C->father = P;


   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}


void AvlTree::RDI(AvlTreeNode* nodo)
{
   cout << "RDI" << endl;
   AvlTreeNode *father = nodo->father;
   AvlTreeNode *P = nodo;
   AvlTreeNode *Q = P->right;
   AvlTreeNode *R = Q->left;
   AvlTreeNode *B = R->left;
   AvlTreeNode *C = R->right;

   if(father)
     if(father->right == nodo) father->right = R;
     else father->left = R;
   else raiz = R;


   P->right = B;
   Q->left = C;
   R->left = P;
   R->right = Q;

   R->father = father;
   P->father = Q->father = R;
   if(B) B->father = P;
   if(C) C->father = Q;

   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}



void AvlTree::RSD(AvlTreeNode* nodo)
{
   cout << "RSD" << endl;
   AvlTreeNode *father = nodo->father;
   AvlTreeNode *P = nodo;
   AvlTreeNode *Q = P->left;
   AvlTreeNode *B = Q->right;

   if(father)
     if(father->right == P) father->right = Q;
     else father->left = Q;
   else raiz = Q;


   P->left = B;
   Q->right = P;

   P->father = Q;
   if(B) B->father = P;
   Q->father = father;


   P->FE = 0;
   Q->FE = 0;
}


void AvlTree::RSI(AvlTreeNode* nodo)
{
   cout << "RSI" << endl;
   AvlTreeNode *father = nodo->father;
   AvlTreeNode *P = nodo;
   AvlTreeNode *Q = P->right;
   AvlTreeNode *B = Q->left;

   if(father)
     if(father->right == P) father->right = Q;
     else father->left = Q;
   else raiz = Q;


   P->right = B;
   Q->left = P;


   P->father = Q;
   if(B) B->father = P;
   Q->father = father;

   P->FE = 0;
   Q->FE = 0;
}


void AvlTree::Borrar(const int dat)
{
   AvlTreeNode *father = nullptr;
   AvlTreeNode *AvlTreeNode;
   int aux;

   actual = raiz;

   while(!isEmpty(actual)) {
      if(dat == actual->data) { 
         if(EsHoja(actual)) {
            if(father) 
              
               if(father->right == actual) father->right = nullptr;
               else if(father->left == actual) father->left = nullptr;
            delete actual; 
            actual = nullptr;
            
            if((father->right == actual && father->FE == 1) ||
               (father->left == actual && father->FE == -1)) {
               father->FE = 0;
               actual = father;
               father = actual->father;
            }
            if(father)
               if(father->right == actual) Equilibrar(father, right, false);
               else                         Equilibrar(father, left, false);
            return;
         }
         else { 

            father = actual;
            if(actual->right) {
               AvlTreeNode = actual->right;
               while(AvlTreeNode->left) {
                  father = AvlTreeNode;
                  AvlTreeNode = AvlTreeNode->left;
               }
            }

            else {
               AvlTreeNode = actual->left;
               while(AvlTreeNode->right) {
                  father = AvlTreeNode;
                  AvlTreeNode = AvlTreeNode->right;
               }
            }


            aux = actual->data;
            actual->data = AvlTreeNode->data;
            AvlTreeNode->data = aux;
            actual = AvlTreeNode;
         }
      }
      else { 
         father = actual;
         if(dat > actual->data) actual = actual->right;
         else if(dat < actual->data) actual = actual->left;
      }
   }
}


void AvlTree::InOrden(void (*func)(int&, int) , AvlTreeNode *AvlTreeNode, bool r)
{
   if(r) AvlTreeNode = raiz;
   if(AvlTreeNode->left) InOrden(func, AvlTreeNode->left, false);
   func(AvlTreeNode->data, AvlTreeNode->FE);
   if(AvlTreeNode->right) InOrden(func, AvlTreeNode->right, false);
}



void AvlTree::PreOrden(void (*func)(int&, int), AvlTreeNode *AvlTreeNode, bool r)
{
   if(r) AvlTreeNode = raiz;
   func(AvlTreeNode->data, AvlTreeNode->FE);
   if(AvlTreeNode->left) PreOrden(func, AvlTreeNode->left, false);
   if(AvlTreeNode->right) PreOrden(func, AvlTreeNode->right, false);
}



void AvlTree::PostOrden(void (*func)(int&, int), AvlTreeNode *AvlTreeNode, bool r)
{
   if(r) AvlTreeNode = raiz;
   if(AvlTreeNode->left) PostOrden(func, AvlTreeNode->left, false);
   if(AvlTreeNode->right) PostOrden(func, AvlTreeNode->right, false);
   func(AvlTreeNode->data, AvlTreeNode->FE);
}


bool AvlTree::Buscar(const int dat)
{
   actual = raiz;


   while(!isEmpty(actual)) {
      if(dat == actual->data) return true; 
      else if(dat > actual->data) actual = actual->right; 
      else if(dat < actual->data) actual = actual->left;
   }
   return false; 
}


int AvlTree::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;


   while(!isEmpty(actual)) {
      if(dat == actual->data) return altura; 
      else {
         altura++;
         if(dat > actual->data) actual = actual->right;
         else if(dat < actual->data) actual = actual->left;
      }
   }
   return -1; 
}


const int AvlTree::NumeroAvlTreeNodes()
{
   contador = 0;

   auxContador(raiz); // FUnci�n auxiliar
   return contador;
}


void AvlTree::auxContador(AvlTreeNode *AvlTreeNode)
{
   contador++;  // Otro AvlTreeNode

   if(AvlTreeNode->left) auxContador(AvlTreeNode->left);
   if(AvlTreeNode->right)   auxContador(AvlTreeNode->right);
}


const int AvlTree::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Funci�n auxiliar
   return altura;
}


void AvlTree::auxAltura(AvlTreeNode *AvlTreeNode, int a)
{
   // Recorrido postorden
   if(AvlTreeNode->left) auxAltura(AvlTreeNode->left, a+1);
   if(AvlTreeNode->right)   auxAltura(AvlTreeNode->right, a+1);

   if(EsHoja(AvlTreeNode) && a > altura) altura = a;
}

// Funci�n de prueba para recorridos del �rbol
void Mostrar(int &d, int FE)
{
   cout << d <<", ";
}

int main()
{

   AvlTree ArbolInt;


    ArbolInt.avlInsert(15);
   ArbolInt.avlInsert(4);
   ArbolInt.avlInsert(20);
   ArbolInt.avlInsert(3);
   ArbolInt.avlInsert(25);
   ArbolInt.avlInsert(6);
   ArbolInt.avlInsert(8);
   ArbolInt.avlInsert(1);
   ArbolInt.avlInsert(2);
   ArbolInt.avlInsert(3);
   ArbolInt.avlInsert(4);
   ArbolInt.avlInsert(5);
   ArbolInt.avlInsert(6);
   ArbolInt.avlInsert(7);
   ArbolInt.avlInsert(8);
   ArbolInt.avlInsert(9);
   ArbolInt.avlInsert(10);
   ArbolInt.avlInsert(11);
   ArbolInt.avlInsert(12);
   ArbolInt.avlInsert(13);
   ArbolInt.avlInsert(14);
   ArbolInt.avlInsert(15);
   ArbolInt.avlInsert(16);

   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;


   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(8);
   ArbolInt.Borrar(11);

   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;


   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   cout << "N AvlTreeNodes: " << ArbolInt.NumeroAvlTreeNodes() << endl;
   ArbolInt.Borrar(5);
   cout << "Borrar   5: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(8);
   cout << "Borrar   8: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(15);
   cout << "Borrar  15: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(245);
   cout << "Borrar 245: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(4);
   cout << "Borrar   4: ";
   ArbolInt.InOrden(Mostrar);
   ArbolInt.Borrar(17);
   cout << endl;
   cout << "Borrar  17: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;


   cout << "N AvlTreeNodes: " << ArbolInt.NumeroAvlTreeNodes() << endl;
   cout << "Altura de 1 " << ArbolInt.Altura(1) << endl;
   cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   cin.get();


   AvlTree<Cadena> ArbolCad;


   ArbolCad.avlInsert("Hola");
   ArbolCad.avlInsert(",");
   ArbolCad.avlInsert("somos");
   ArbolCad.avlInsert("buenos");
   ArbolCad.avlInsert("programadores");


   cout << "InOrden: ";
   ArbolCad.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolCad.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolCad.PostOrden(Mostrar);
   cout << endl;

   
   ArbolCad.Borrar("buenos");
   cout << "Borrar 'buenos': ";
   ArbolCad.InOrden(Mostrar);
   cout << endl; 
   cin.get();
   return 0;
}
