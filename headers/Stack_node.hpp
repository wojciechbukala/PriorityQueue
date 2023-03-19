#ifndef STACK_NODE
#define STACK_NODE

#include <cstddef>
#include <iostream>

template <typename T>
class Stack_node
{
    protected:

        T element;
        Stack_node<T>* next;
    
    public:

        Stack_node();
        Stack_node(T init_elem);
        Stack_node(T init_elem, Stack_node<T>* next_ptr);

        T getElement();
        Stack_node<T>* getNext();

        void setElement(T NewElem);
        void setNext(Stack_node<T>* newNode);
};

template <typename T>
Stack_node<T>::Stack_node()
{
    next = NULL;
}

template <typename T>
Stack_node<T>::Stack_node(T init_elem)
{
    element = init_elem;
    next = NULL;
}

template <typename T>
Stack_node<T>::Stack_node(T init_elem, Stack_node<T>* next_ptr)
{
    element = init_elem;
    next = next_ptr;
}

template <typename T>
T Stack_node<T>::getElement()
{
    return element;
}


template <typename T>
Stack_node<T>* Stack_node<T>::getNext()
{
    return next;
}


template <typename T>
void Stack_node<T>::setElement(T NewElem)
{
    element = NewElem;
}

template <typename T>
void Stack_node<T>::setNext(Stack_node<T>* newNode)
{
    next = newNode;
}

#endif