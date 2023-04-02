#ifndef STACK
#define STACK
#include "Stack_node.hpp"

template <typename T>
class Stack : public Stack_node<T>
{
    public:
        Stack();
        //~PriorityStack();
        bool empty();
        int size();
        void push(T new_elem);
        void view();
        Stack_node<T> remove();
        //void mix(int size);

    private:
        Stack_node<T>* head;
        Stack_node<T>* tail;
        int Stack_size;
};

template <typename T>
Stack<T>::Stack()
{
    head = NULL;
    tail = NULL;
    Stack_size = 0;

}

template <typename T>
bool Stack<T>::empty()
{
    if(head == NULL) return 1;
    else return 0;
}

template <typename T>
int Stack<T>::size()
{
    return Stack_size;
}

template <typename T>
void Stack<T>::push(T new_elem)
{
    Stack_node<T>* temp = new Stack_node<T>(new_elem);
    
    if(empty())
    {
        head = temp;
        tail = temp;
        Stack_size = 1;
    }
    else 
    {
    // adding node after the head
        temp->setNext(head);
        head = temp;
        Stack_size++;
    }
}

template <typename T>
Stack_node<T> Stack<T>::remove()
{
    Stack_node<T> temp = *head;
    Stack_node<T>* temp_ptr = head;

    head = head->getNext();

    temp_ptr->setNext(NULL);

    Stack_size--;

    return temp; 
}

template <typename T>
void Stack<T>::view()
{
    Stack_node<T>* ptr = NULL;

    try{
        if(empty()) 
        {
            throw 1;
        }
        else
        {
            ptr = head;
            int iterator = 1;

            std::cout << "0. HEAD" << std::endl;

            while(ptr != tail->getNext())
            {
                std::cout<< iterator << ". ELEMENT " << ptr->getElement() << " O ADRESIE: " << ptr << std::endl;
                ptr = ptr->getNext();
                iterator++;
            }

            std::cout << iterator << ". TAIL" << std::endl;
        }
    }

    catch (int error_num)
    {
        std::cout << "STOS JEST PUSTY. NIE MOŻNA WYŚWIETLIĆ ELEMENTÓW" << std::endl;
    }
}


#endif