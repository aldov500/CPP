#include "node.h"

/*  Constructores  */
Node::Node() {
    nextAddr = nullptr;
    prevAddr = nullptr;
    }

Node::Node(Song data, Node* next, Node* prev ) {
    this->data      = data;
    this->nextAddr  = next;
    this->prevAddr  = prev;
    }


/*  Setters  */
void Node::setData(Song &data) {
    this->data = data;
    }

void Node::setNext(Node *next) {
    this->nextAddr = next;
    }

void Node::setPrev(Node *prev) {
    this->prevAddr = prev;
    }


/*  Getters  */
Song& Node::getData() {
    return data;

    }

Node* Node::getNext() {
    return nextAddr;
    }

Node *Node::getPrev() {
    return prevAddr;
    }

/*  Impresiones  */
void Node::printNode() {
    cout<< "________________________________"<<endl;
    cout<< "Direccion: " << this << " -> Siguiente: " << nextAddr << endl;
    data.printSong();

    }

