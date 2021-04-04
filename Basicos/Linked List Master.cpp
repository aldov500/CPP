#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

/// collection.h (c) 2016 by Alfredo Gutierrez
/// collection.h is licensed under a
/// Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
/// You should have received a copy of the license along with this
/// work. If not, see <http://creativecommons.org/licenses/by-nc-sa/3.0/>

#include <exception>
#include <iostream>
#include <string>

template <class T>  class Collection {
    protected:
        class Node {
            private:
                T* dataPtr;
                Node* prev;
                Node* next;

            public:
                class NodeException : public std::exception {
                    protected:
                        std::string msg;

                    public:
                        explicit NodeException(const char* message) : msg(message) { }

                        explicit NodeException(const std::string& message) : msg(message) { }

                        virtual ~NodeException() throw () { }

                        virtual const char* what() const throw () {
                            return msg.c_str();
                            }
                    };

                Node() : dataPtr(nullptr), prev(nullptr), next(nullptr) { }

                Node(const Node& n) : Node(*n.dataPtr) { }

                Node(const T& e, Node* p = nullptr, Node* n = nullptr) : prev(p), next(p) {
                    if((dataPtr = new T(e)) == nullptr) {
                        throw NodeException("Not available memory, creating new node");
                        }
                    }

                ~Node() {
                    delete dataPtr;
                    }

                Node& operator=(const Node& n) {
                    if((dataPtr = new T(*n.dataPtr)) == nullptr) {
                        throw NodeException("Not available memory, creating new node");
                        }

                    prev = next = nullptr;
                    }

                T* getdataPtr() {
                    return dataPtr;
                    }

                Node* getPrev() {
                    return prev;
                    }

                Node* getNext() {
                    return next;
                    }

                T& getData() {
                    return *dataPtr;
                    }

                void setdataPtr(T* p) {
                    dataPtr = p;
                    }

                void setPrev(Node* p) {
                    prev = p;
                    }

                void setNext(Node* p) {
                    next = p;
                    }

                void setData(const T& e) {
                    if(dataPtr = nullptr) dataPtr = new T;

                    if(dataPtr != nullptr) *dataPtr = e;
                    }
            };

        friend class Collection::Node;

        Node* header;
        unsigned int itemCounter;
        bool isOrdered;

        bool isValidPos(Node* p) {
            if(p == nullptr) return false;

            Node* aux = header->getNext();
            while(aux != header) {
                if(aux == p) return true;

                aux = aux->getNext();
                }

            return false;
            }

        Node* idxToPos(int idx) {
            if(idx < 0 or idx >= itemCounter) return nullptr;

            Node* aux;
            int i;
            for(i = 0, aux = header->getNext(); aux != header and i < idx; aux = aux->getNext(), i++);

            return aux;
            }

        void copyCollection(Collection<T>& c) {
            Node* aux = c.header->getNext();

            while(aux != c.header) {
                insertData(aux->getData());

                aux = aux->getNext();
                }
            }

        void swapData(Node* a, Node* b) {
            T* aux = a->getdataPtr();
            a->setdataPtr(b->getdataPtr());
            b->setdataPtr(aux);
            }

        void qckSort(Node* left, Node* right) {
            if(left == right) return;

            if(left->getNext() == right) {
                if(left->getData() > right->getData()) swapData(left, right);

                return;
                }

            Node *i = left, *j = right;

            while(i != j) {
                while(i != j and i->getData() <= right->getData())  i = i->getNext();

                while(i != j and j->getData() > right->getData()) j = j->getPrev();

                if(i != j) swapData(i, j);
                }

            if(i != right) swapData(i, right);

            if(i != left) qckSort(left, i->getPrev());

            if(i != right) qckSort(i->getNext(), right);
            }

    public:
        class CollectionException : public std::exception {
            protected:
                std::string msg;

            public:
                explicit CollectionException(const char* message) : msg(message) { }

                explicit CollectionException(const std::string& message) : msg(message) { }

                virtual ~CollectionException() throw () { }

                virtual const char* what() const throw () {
                    return msg.c_str();
                    }
            };

        typedef Node* CollPos;

        Collection() : header(nullptr), itemCounter(0), isOrdered(true) {
            if((header = new Node) == nullptr) {
                throw CollectionException("Memory not available, creating collection");
                }

            header->setPrev(header);
            header->setNext(header);
            }

        Collection(Collection<T>& c) : Collection<T>() {
            copyCollection(c);
            }

        ~Collection() {
            deleteAll();
            }

        bool isEmpty() {
            return header->getNext() == header;
            }

        Node* insertData(Node* p, const T& e) {
            if(p != nullptr and !isValidPos(p)) throw CollectionException("Invalid position, insert");

            if(p == nullptr) p = header;

            Node* aux;
            if((aux = new Node(e, p, p->getNext())) == nullptr) throw CollectionException("Memory not available, inserting");

            p->getNext()->setPrev(aux);
            p->setNext(aux);

            itemCounter++;
            isOrdered = false;

            return aux;
            }

        Node* insertData(const T& e) {
            Node* p = header->getPrev();
            Node* aux;

            if((aux = new Node(e, p, p->getNext())) == nullptr) throw CollectionException("Memory not available, inserting");

            p->getNext()->setPrev(aux);
            p->setNext(aux);

            itemCounter++;
            isOrdered = false;

            return aux;
            }

        Node* insertOrderedData(const T& e) {
            if(!isOrdered)
                sortData();

            Node* p = header;
            Node* aux = header->getNext();
            while(aux != header and e >= aux->getData()) {
                p = aux;
                aux = aux->getNext();
                }

            aux = new Node(e, p, p->getNext());
            if(aux == nullptr)
                throw CollectionException("Memory not available, inserting");

            p->getNext()->setPrev(aux);
            p->setNext(aux);

            itemCounter++;
            isOrdered = true;

            return aux;
            }

        Node* push(T e) {
            Node* p = header;
            Node* aux;

            if((aux = new Node(e, p, p->getNext())) == nullptr) {
                throw CollectionException("Memory not available, inserting");
                }

            p->getNext()->setPrev(aux);
            p->setNext(aux);

            itemCounter++;
            isOrdered = false;

            return aux;
            }

        Node* enqueue(const T& e) {
            return insertData(e);
            }

        Node* enqueuePriorized(const T& e) {
            if(!isOrdered) {
                sortData();
                }

            return insertOrderedData(e);
            }

        void deleteData(const T& e) {
            Node* p = findData(e);

            if(p != nullptr) {
                deleteData(p);
                }
            }

        void deleteData(Node* p) {
            if(isEmpty())
                throw CollectionException("Insufficient data, deleteData");

            if(!isValidPos(p))
                throw CollectionException("Invalid position, deleteData");

            p->getPrev()->setNext(p->getNext());
            p->getNext()->setPrev(p->getPrev());

            itemCounter--;
            delete p;
            }

        void deleteAll() {
            Node* aux;
            while(header->getNext() != header) {
                aux = header->getNext();
                header->setNext(header->getNext()->getNext());

                delete aux;
                }

            header->setPrev(header);
            itemCounter = 0;
            }

        T pop() {
            if(isEmpty())
                throw CollectionException("Insufficient data, pop");

            T r = header->getNext()->getData();

            deleteData(getFirst());

            return r;
            }

        T dequeue() {
            if(isEmpty())
                throw CollectionException("Insufficient data, dequeue");

            T r = header->getNext()->getData();

            deleteData(getFirst());

            return r;
            }

        Node* getFirst() {
            if(isEmpty())
                return nullptr;

            return header->getNext();
            }

        Node* getLast() {
            if(isEmpty())
                return nullptr;

            return header->getPrev();
            }

        Node* getPrev(Node* p) {
            if(isEmpty() or !isValidPos(p))
                return nullptr;

            return p->getPrev();
            }

        Node* getNext(Node* p) {
            if(isEmpty() or !isValidPos(p))
                return nullptr;

            return p->getPrev();
            }

        Node* findData(T e) {
            if(isEmpty())
                return nullptr;

            Node* aux = header->getNext();
            while(aux != header) {
                if(aux->getData() == e)
                    return aux;

                aux = aux->getNext();
                }

            return nullptr;
            }

        T& retrieveData(Node* p) {
            if(!isValidPos())
                throw CollectionException("Invalid position, retrieve");

            return p->getData();
            }

        T getTop() {
            if(isEmpty())
                throw CollectionException("Insufficient data, getTop");

            return header->getNext()->getData();
            }

        T getFront() {
            if(isEmpty())
                throw CollectionException("Insufficient data, getFront");

            return header->getNext()->getData();
            }

        void sortData() {
            qckSort(header->getNext(), header->getPrev());
            }

        T& operator[](int idx) {
            return retrieveData(idxToPos(idx));
            }

        Collection operator+(const Collection<T>& c) {
            copyCollection(c);

            return *this;
            }

        Collection operator=(const Collection& c) {
            deleteAll();

            copyCollection(c);

            return *this;
            }


        friend std::ostream& operator<<(std::ostream& os, Collection<T>& c) {
            Node* aux = c.header->getNext();
            while(aux != c.header) {
                os << aux->getData() << std::endl;

                aux = aux->getNext();
                }

            return os;
            }

        friend std::istream& operator>>(std::istream& is, Collection<T>& c) {
            T e;

            while(is >>  e) c.insertData(e);

            return is;
            }
    };

#endif // COLLECTION_H_INCLUDED