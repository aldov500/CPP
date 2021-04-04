#include "binaryTree.h"

void binaryTree::pruneTree(Node* node) {
    if(node) {
        pruneTree(node->getSubIzq());
        pruneTree(node->getSubDer());
        delete node;
        node = nullptr;
        }

    }

void binaryTree::auxCounter(Node* n) {
    i++;
    if(n->getSubIzq())
        auxCounter(n->getSubIzq());
    if(n->getSubDer())
        auxCounter(n->getSubDer());

    }

void binaryTree::auxHeight(Node* n, int e) {
    if(n->getSubIzq())
        auxHeight(n->getSubIzq(), e+1);
    if(n->getSubDer())
        auxHeight(n->getSubDer(), e+1);

    if(isLeaf(n) && e > height)
        height = e;
    }

binaryTree::binaryTree() {
    root = nullptr;
    actual = nullptr;
    }

binaryTree::~binaryTree() {
    pruneTree(root);
    }

void binaryTree::treeInsert(const int elem) {
    Node* father = nullptr;
    actual = root;

    while(!isEmpty(actual) && elem != actual->getData() ) {
        father = actual;

        if(elem < actual->getData())
            actual = actual->getSubIzq();
        else
            actual = actual->getSubDer();
        }

    if(!isEmpty(actual))
        return;

    if(isEmpty(father))
        root = new Node(elem, nullptr,nullptr);

    else if(elem < father->getData())
        father->setSubDer(new Node(elem,nullptr,nullptr));

    else if(elem > father->getData())
        father->setSubDer(new Node(elem,nullptr,nullptr));

    }

void binaryTree::treeDelete(const int elem) {
    Node* father;
    Node* node;
    int aux;

    actual = root;

    while(!isEmpty(actual)){
        if(elem == actual->getData()){
            if(isLeaf(actual)){
                if(father){
                    if(father->getSubDer() == actual)
                        father->setSubDer(nullptr);
                    else if(father->getSubIzq() == actual)
                        father->setSubIzq(nullptr);
                }
                delete actual;
                return;
                }

            else{
                father = actual;

                if(actual->getSubDer()){
                    node = actual->getSubDer();
                    while(node->getSubIzq()){
                        father = node;
                        node = node->getSubIzq();
                    }
                }
                else{
                    node = actual->getSubIzq();
                    while(node->getSubDer()){
                        father = node;
                        node = node->getSubDer();
                    }
                }

                aux = actual->getData();
                actual->setData(node->getData());
                node->setData(aux);
                actual = node;
            }

        }
        else{
            father = actual;
            if(elem < actual->getData())
                actual = actual->getSubIzq();
            else if(elem > actual->getData())
                actual = actual->getSubDer();
        }


    }
    }

bool binaryTree::isSearch(const int elem) {
    actual = root;

    while(!isEmpty(actual)) {
        if(elem == actual->getData())
            return true;
        else if(elem < actual->getData())
            actual = actual->getSubIzq();
        else if(elem > actual->getData())
            actual = actual->getSubDer();

        }
    return false;
    }

bool binaryTree::isEmpty(Node* n) {
    return (n == nullptr);
    }

bool binaryTree::isLeaf(Node* n) {
    return (n->getSubDer() == nullptr && n->getSubIzq() == nullptr);
    }

const int binaryTree::nodeCounter() {
    i = 0;

    auxCounter(root);
    return i;
    }

const int binaryTree::treeHeight() {
    height = 0;

    auxHeight(root,0);
    return height;
    }

int binaryTree::getElemHeight(const int elem) {
    int altura = 0;
    actual = root;

    while(!isEmpty(actual)) {
        if(elem == actual->getData())
            return altura;
        else {
            altura++;
            if(elem < actual->getData())
                actual = actual->getSubIzq();
            else if(elem > actual->getData())
                actual = actual->getSubDer();

            }

        }
    return -1;
    }

int binaryTree::getActElem() {
    return actual->getData();

    }

void binaryTree::goToRoot() {
    actual = root;
    }

void binaryTree::treePreOrder(void (*func)(int), Node* node, bool r) {
    if(r)
        node = root;
    func(node->getData());
    if(node->getSubIzq())
        treePreOrder(func,node->getSubIzq(), false);
    if(node->getSubDer())
        treePreOrder(func,node->getSubDer(), false);
    }

void binaryTree::treeInOrder(void (*func)(int), Node* node, bool r) {
    if(r)
        node = root;
    if(node->getSubIzq())
        treeInOrder(func, node->getSubIzq(),false);
    func(node->getData());
    if(node->getSubDer())
        treeInOrder(func, node->getSubDer(), false);
    }

void binaryTree::treePostOrder(void (*func)(int), Node* node, bool r) {
    if(r)
        node = root;
    if(node->getSubIzq())
        treePostOrder(func, node->getSubIzq(),false);
    if(node->getSubDer())
        treePostOrder(func, node->getSubDer(), false);

    func(node->getData());
    }

