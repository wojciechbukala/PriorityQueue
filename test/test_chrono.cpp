#include <iostream>
#include <chrono>
#include "PQueue.hpp"



using namespace std;
using namespace std::chrono;


bool Performance_test(int elem_quantity)
{
    PriorityQueue<std::string> q;

    //100 elements queue, the worst case pushing
    int key = elem_quantity;
    auto start_push1 = high_resolution_clock::now();
    for(int i=0; i<elem_quantity; ++i)
    {

        q.push("elem", key);
        key--;
    }
    auto stop_push1 = high_resolution_clock::now();
    auto duration_push1 = duration_cast<microseconds>(stop_push1-start_push1);


    //100 elements queue, the worst case removing
    auto start_remove1 = high_resolution_clock::now();
    for(int i=0; i<elem_quantity; ++i)
    {

        q.removeMax();
    }
    auto stop_remove1 = high_resolution_clock::now();
    auto duration_remove1 = duration_cast<microseconds>(stop_remove1-start_remove1);


    key = 0;
    if(!q.empty()) 
    {
        cout << "Erorr" << endl;
        return 0;
    }


    //100 elements, the best case pushing
    auto start_push2 = high_resolution_clock::now();
    for(int i=0; i<elem_quantity; ++i)
    {

        q.push("elem", key);
        key++;
    }
    auto stop_push2 = high_resolution_clock::now();
    auto duration_push2 = duration_cast<microseconds>(stop_push2-start_push2);

    //100 elements, the worst case removing
    auto start_remove2 = high_resolution_clock::now();
    for(int i=0; i<elem_quantity; ++i)
    {

        q.removeMax();
    }
    auto stop_remove2 = high_resolution_clock::now();
    auto duration_remove2 = duration_cast<microseconds>(stop_remove2-start_remove2);

    cout << elem_quantity << " elements: " << endl;
    cout << "The worst case pushing : " << duration_push1.count() << " microseconds" << endl;
    cout << "The worst case removing: " << duration_remove1.count() << " microseconds" << endl;
    cout << "The best case pushing  : " << duration_push2.count() << " microseconds" << endl;
    cout << "The best case removing : " << duration_remove2.count() << " microseconds" << endl;

    return 1;

}

int main()
{
    if(!Performance_test(100)) cout << "test failed" << endl;
    if(!Performance_test(1000)) cout << "test failed" << endl;
    if(!Performance_test(100000)) cout << "test failed" << endl;
}

/*
int main()
{
    cout << "Program bazujący na kolejce priorytetowej" << endl;

    char w = ' ';
    std::string t = " ";
    int p = 0;
    PriorityQueue<std::string> p_queue;
    Node<std::string> elem;

    do
    {
        cout << "Menu wyboru:" << endl;
        cout << "P - podawanie pakietu." << endl;
        cout << "O - odszyfrowywanie sekwencji." << endl;
        cout << "E - koniec programu" << endl;
        cin >> w;

        switch (w)
        {
        case 'P':
            cout << endl << "Podaj tresc: ";
            cin >> t;
            cout << "Podaj priorytet: ";
            cin >> p;

            p_queue.push(t,p);
            break;

        case 'O':

        cout << "Wiadomosc: " <<endl;

        while(!p_queue.empty())
        {
            cout << p_queue.removeMax().getElement() << " ";
        } 
        cout << endl << endl;
        break;

        case 'E':
        cout << "Exit" << endl;
        break;
     
        default:
        cout << "Podano bledna opcje, sprobuj jeszcze raz" << endl;
            break;
        }
    } while(w != 'E');
    
    return 0;
} */