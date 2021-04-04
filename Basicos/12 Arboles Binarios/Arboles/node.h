#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>

using namespace std;


class Node {

    private:
        int data;

        Node* subIzq;
        Node* subDer;

    public:

        Node();
        Node(int d, Node* sI, Node* sD);

        int  getData();
        Node* getSubIzq();
        Node* getSubDer();
        Node* getParent();

        void setData(int d);
        void setSubIzq(Node* sI);
        void setSubDer(Node* sD);
        void setParent(Node* p);

        void printNode();
    };

#endif // NODE_H_INCLUDED

