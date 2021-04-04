#include "linkedList.h"

/*  Constructores  */

LinkedList::LinkedList() {
    head = nullptr;
    }

LinkedList::LinkedList(Node *n) {
    head = n;
    }

LinkedList::~LinkedList() {
    nullData();
    }

/*  Manejo de datos  */
void LinkedList::insertNode(Node* pos, Song data) {
    Node *aux = new Node();
    aux->setData(data);

    if(pos == nullptr) {
        aux->setPrev(nullptr);
        aux->setNext(head);

        if(head != nullptr) {
            head->setPrev(aux);
            }
        head = aux;

        }

    else {
        aux->setPrev(pos);
        aux->setNext(getNext(pos));

        if(pos->getNext() != nullptr) {
            pos->getNext()->setPrev(aux);
            }
        pos->setNext(aux);

        }
    }

void LinkedList::deleteNode(Node* pos) {
    if(isEmpty() || pos == nullptr) {
        return;
        }
    if(pos->getPrev() != nullptr) {
        pos->getPrev()->setNext(pos->getNext());
        }
    if(pos->getNext() != nullptr) {
        pos->getNext()->setPrev(pos->getPrev());
        }
    if(pos == head) {
        head = head->getNext();
        }
    delete pos;
    }

void LinkedList::sortData() {
    Node *limit = nullptr;
    Node *aux = head;
    int contador,i = 0;

    while(aux != limit) {
        contador++;
        aux = aux->getNext();
        }
    Node **arreglo;
    arreglo = new Node *[contador];

    aux = head;
    while(aux != limit) {
        arreglo[i] = aux;
        aux = aux->getNext();
        i++;
        }

    quickSort(arreglo,0,contador-1);

    i = 0;
    while(i < contador-1) {
        arreglo[i]->setNext(arreglo[i+1]);
        i++;
        }
    arreglo[i]->setNext(limit);
    arreglo[0]->setPrev(limit);

    i = 1;
    while(i < contador-1) {
        arreglo[i]->setPrev(arreglo[i-1]);
        i++;
        }

    head = arreglo[0];

    delete arreglo;

    }

void LinkedList::quickSort(Node **arreglo, int izq, int der) {
    int i, j, centro;
    Node *temp;
    Node *pivote;

    i = izq;
    j = der;
    centro = (izq + der)/2;
    pivote = arreglo[centro];
    temp = nullptr;

    while(i <= j) {
        while(arreglo[i]->getData() < pivote->getData()) i++;
        while(arreglo[j]->getData() > pivote->getData()) j--;

        if(i <= j) {
            temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
            i++;
            j--;
            }
        }

    if(izq < j) {
        quickSort(arreglo,izq,j);
        }
    else if(i < der) {
        quickSort(arreglo, i, der);
        }

    }

void LinkedList::nullData() {
    Node *aux;

    while(head != NULL) {
        aux = head;
        head = head->getNext();
        delete aux;
        }

    }

Song LinkedList::getData(Node* pos) {
    if(isEmpty() || pos == nullptr) {
        throw NodeException("Insuficiencia de datos.");
        }
    else {
        return pos->getData();
        }
    }

Node* LinkedList::getFirst() {
    return head;
    }

Node* LinkedList::getLast() {
    if(isEmpty()) {
        return nullptr;
        }
    Node *aux = head;

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        }
    return aux;
    }

Node* LinkedList::getPrev(Node* pos) {
    if(isEmpty() || pos == nullptr) {
        return nullptr;
        }
    return pos->getPrev();
    }

Node* LinkedList::getNext(Node* pos) {
    if(isEmpty() || pos == nullptr) {
        return nullptr;
        }
    return pos->getNext();
    }

Node* LinkedList::locateNode(Song sng) {
    Node *aux = head;
    while(aux != nullptr && aux->getData() != sng) {
        aux = aux->getNext();
        }
    return aux;
    }

bool LinkedList::isEmpty() {
    return (head==nullptr);
    }

void LinkedList::printList() {
    Node *aux = head;

    while(aux != nullptr) {
        aux->printNode();
        aux = aux->getNext();
        }

    }

Song LinkedList::createSong(const string& t, const string& a, const string& rl, const string& g ) {
    Song temp;

    temp.setTitle(t);
    temp.setAuthor(a);
    temp.setRecordL(rl);
    temp.setGenre(g);
    temp.setMP3(a,t);

    return temp;

    }

Node* LinkedList::locateByTitle(string s) {
    Node *aux = head;

    while(aux != nullptr &&  aux->getData().getTitle() != s) {
        aux = aux->getNext();
        }
    return aux;

    }

