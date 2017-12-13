#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include "nodeException.h"
#include "song.h"

/*  TIPO SONG   */
class Node {
    private:
        Song data;
        Node *nextAddr;

    public:

        Node();
        Node(Song, Node*, Node*);

        void setData(Song &e);
        void setNext(Node*);
        void setPrev(Node*);

        Song&  getData();
        Node *getNext();

        void printNode();
    };


#endif // NODE_H_INCLUDED
