#ifndef PQUEUE
#define PQUEUE
#include "Node.hpp"

template <typename T>
class PriorityQueue : public Node<T>
{
    public:
        PriorityQueue();
        //~PriorityQueue();
        bool empty();
        int size();
        void push(T new_elem, int new_key);
        void view();
        Node<T> removeMin();
        Node<T> removeMax();

    private:
        Node<T>* head;
        Node<T>* tail;
        int queue_size;
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    head = NULL;
    tail = NULL;
    queue_size = 0;

}

template <typename T>
bool PriorityQueue<T>::empty()
{
    if(head == NULL) return 1;
    else return 0;
}

template <typename T>
int PriorityQueue<T>::size()
{
    return queue_size;
}

template <typename T>
void PriorityQueue<T>::push(T new_elem, int new_key)
{
    Node<T>* temp = new Node<T>(new_elem,new_key);
    Node<T>* temp_pointer = NULL; 
    
    if(empty())
    {
        head = temp;
        tail = temp;
        queue_size = 1;
    }
    else if(!empty()) //adding on the end of the queue
    {

        temp_pointer = head;
        bool inserted = 0;

        while(temp_pointer != tail->getNext())
        {
            if(new_key > temp_pointer->getKey())
            {
                // adding node after the head
                if(temp_pointer->getPrev() == NULL)
                {
                    temp->setNext(head);
                    head = temp;
            
                    head->setPrev(NULL);
                    temp->getNext()->setPrev(temp);
                }
                // adding node between two others nodes
                else
                {
                    temp->setPrev(temp_pointer->getPrev());
                    temp->setNext(temp_pointer);

                    temp_pointer->setPrev(temp);
                    (temp->getPrev())->setNext(temp);
                }
                inserted = 1;
                queue_size++;
                break;
            }

            temp_pointer = temp_pointer->getNext();
        }

        // adding node before tail
        if(!inserted)
        {
            temp->setPrev(tail);
            tail = temp;

            tail->setNext(NULL);
            temp->getPrev()->setNext(temp);

            queue_size++;
        }

    }
}

template <typename T>
Node<T> PriorityQueue<T>::removeMax()
{
    try
    {
        if(!empty())
        {
            Node<T> temp = *head;
            Node<T>* temp_ptr = head;

            head = head->getNext();

            if(head != NULL) head->setPrev(NULL);

            temp_ptr->setNext(NULL);
            temp_ptr->setPrev(NULL);

            queue_size--;

            return temp;
        } 
        else
        {
            throw std::runtime_error("empty queue");
        }
    }
    catch(std::runtime_error &e)
    {
        std::cout << "KOLEJKA JEST PUSTA NIE MOZNA USUNAC ELEMENTOW." << std::endl;

    } 
}

template <typename T>
Node<T> PriorityQueue<T>::removeMin()
{
    Node<T> temp = *tail;
    Node<T>* temp_ptr = tail;

    tail = tail->getPrev();

    tail->setNext(NULL);

    temp_ptr->setNext(NULL);
    temp_ptr->setPrev(NULL);

    queue_size--;

    return temp; 
}


template <typename T>
void PriorityQueue<T>::view()
{
    Node<T>* ptr = NULL;

    try{
        if(empty()) 
        {
            throw 1;
            //std::cout << "KOLEJKA JEST PUSTA. NIE MOŻNA WYŚWIETLIĆ ELEMENTÓW" << std::endl;
        }
        else
        {
            ptr = head;
            int iterator = 1;

            std::cout << "0. HEAD" << std::endl;

            while(ptr != tail->getNext())
            {
                std::cout<< iterator << ". ELEMENT " << ptr->getElement()<<","<< ptr->getKey() << " O ADRESIE: " << ptr << std::endl;
                ptr = ptr->getNext();
                iterator++;
            }

            std::cout << iterator << ". TAIL" << std::endl;
        }
    }

    catch (int error_num)
    {
        std::cout << "KOLEJKA JEST PUSTA. NIE MOŻNA WYŚWIETLIĆ ELEMENTÓW" << std::endl;
    }
}


#endif