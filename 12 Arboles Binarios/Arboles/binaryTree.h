#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "node.h"

class binaryTree {
	private:
    	int i;
    	int height;
    	Node* root;
    	Node* actual;

    	void pruneTree(Node* node);
    	void auxCounter(Node* n);
    	void auxHeight(Node* n, int e);

 	public:

    	binaryTree();
        ~binaryTree();

        void treeInsert(const int elem);
        void treeDelete(const int elem);

        bool isSearch(const int elem);
        bool isEmpty(Node* n);
        bool isLeaf(Node* n);

        const int nodeCounter();
        const int treeHeight();

        int getElemHeight(const int elem);
        int getActElem();

        void goToRoot();

   		void treePreOrder(void (*func)(int) , Node* nodo= nullptr, bool r=true);
        void treeInOrder(void (*func)(int) , Node* nodo= nullptr, bool r=true);
        void treePostOrder(void (*func)(int) , Node* nodo= nullptr, bool r=true);

};

#endif // BINARYTREE_H_INCLUDED
