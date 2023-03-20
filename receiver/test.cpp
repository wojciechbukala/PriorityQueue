#include <iostream>
#include "PQueue.hpp"



using namespace std;

int main()
{

    PriorityQueue<std::string> e;
    PriorityQueue<std::string> poped;
    e.push("Wojtek",1);
    e.push("Mati",2);
    e.push("Janusz",2);
    e.push("Marcin",4);
    e.view();
    cout << "Size:" << e.size() << endl; 
    e.removeMax();
    e.removeMax();
    e.view();
    cout << "Size:" << e.size() << endl; 
    e.removeMax();
    e.removeMax();
    //e.removeMax();
    e.view();
    return 0;
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