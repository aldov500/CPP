#include "node.h"

/*  Constructores  */
Node::Node() {
    nextAddr = nullptr;
    }

Node::Node(Song data, Node* next, Node* prev ) {
    this->data      = data;
    this->nextAddr  = next;
    }


/*  Setters  */
void Node::setData(Song &data) {
    this->data = data;
    }

void Node::setNext(Node *next) {
    this->nextAddr = next;
    }

/*  Getters  */
Song& Node::getData() {
    return data;

    }

Node* Node::getNext() {
    return nextAddr;
    }

/*  Impresiones  */
void Node::printNode() {
    cout<< "________________________________"<<endl;
    cout<< "Direccion: " << this << " -> Siguiente: " << nextAddr << endl;
    data.printSong();

    }

