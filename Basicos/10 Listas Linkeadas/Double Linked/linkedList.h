#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "node.h"

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList(Node *n);
        LinkedList();
        ~LinkedList();

        void insertNode(Node* pos, Song data);
        void deleteNode(Node* pos);
        void sortData();
        void quickSort(Node **arreglo, int izq, int der);
        void nullData();

        Node* getFirst();
        Node* getLast();
        Node* getPrev(Node *pos);
        Node* getNext(Node *pos);
        Node* locateNode(Song ing);
        Node* locateByTitle(string);


        bool isEmpty();
        void printList();

        Song createSong(const string&, const string&, const string&, const string&);
        Song getData(Node *pos);


    };


#endif // LINKEDLIST_H_INCLUDED
