#include "node.h"

Node::Node() {
    subIzq = nullptr;
    subDer = nullptr;
    }

Node::Node(int d,  Node* sI, Node* sD) {
    data = d;
    subIzq = sI;
    subDer = sD;
    }


int Node::getData() {
    return data;
    }

Node* Node::getSubIzq() {
    return subIzq;
    }

Node* Node::getSubDer() {
    return subDer;
    }


void Node::setData(int d) {
    data = d;
    }

void Node::setSubIzq(Node* sI) {
    subIzq = sI;
    }

void Node::setSubDer(Node* sD) {
    subDer = sD;
    }


void Node::printNode() {
    cout<< "________________________________"<<endl;
    cout<< "Addr: " << this << " -> Izq: " << subIzq <<" -> Der: " << subDer << endl;
    cout<< "Valor: " << data <<endl;
    }

