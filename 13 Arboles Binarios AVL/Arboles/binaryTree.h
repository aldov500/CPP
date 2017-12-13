#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "node.h"

class binaryTree {
	private:
    	Node* root;

 	public:

    	binaryTree();
        ~binaryTree();

        bool isEmpty(Node* n);
        bool isLeaf(Node* n);

        void insertData(const int elem, Node* arbol);
        void deleteData(const int elem);

        Node* getMinor(Node* arbol);
        Node* getMayor(Node* arbol);
        Node* getRoot();

        Node* locateNode(const int elem, Node* arbol);

        int recoverData(Node* n);

   		void PreOrder(Node* arbol);
        void InOrder();
        void PostOrder();

        void deleteAll();
};

#endif // BINARYTREE_H_INCLUDED
