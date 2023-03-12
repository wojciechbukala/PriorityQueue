#ifndef NODE
#define NODE

#include <cstddef>
#include <iostream>

template <typename T>
class Node
{
    protected:

        T element;
        Node<T>* next;
        Node<T>* prev;
        unsigned short key;
    
    public:

        Node();
        Node(T init_elem, unsigned short init_key);
        Node(T init_elem, unsigned short init_key, Node<T>* next_ptr, Node<T>* prev_ptr);

        T getElement();
        int getKey();
        Node<T>* getNext();
        Node<T>* getPrev();

        void setElement(T NewElem);
        void setKey(int NewKey);
        void setNext(Node<T>* newNode);
        void setPrev(Node<T>* newNode);


};

template <typename T>
Node<T>::Node()
{
    next = NULL;
    prev = NULL;
}

template <typename T>
Node<T>::Node(T init_elem, unsigned short init_key)
{
    element = init_elem;
    key = init_key;
    next = NULL;
    prev = NULL;
}

template <typename T>
Node<T>::Node(T init_elem, unsigned short init_key, Node<T>* next_ptr, Node<T>* prev_ptr)
{
    element = init_elem;
    key = init_key;
    next = next_ptr;
    prev = next_ptr;
}

template <typename T>
T Node<T>::getElement()
{
    return element;
}

template <typename T>
int Node<T>::getKey()
{
    return key;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
    //std::cout<<&next<<std::endl;
    return next;
}

template <typename T>
Node<T>* Node<T>::getPrev()
{
    return prev;
} 

template <typename T>
void Node<T>::setElement(T NewElem)
{
    element = NewElem;
}

template <typename T>
void Node<T>::setKey(int NewKey)
{
    key = NewKey;
}

template <typename T>
void Node<T>::setNext(Node<T>* newNode)
{
    //std::cout<<&newNode<<std::endl;
    next = newNode;
}

template <typename T>
void Node<T>::setPrev(Node<T>* newNode)
{
    prev = newNode;
} 

#endif