#include <iostream>
#include "Queue.hpp"

using namespace std;

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
        break;
     
        default:
        cout << "Podano bledna opcje, sprobuj jeszcze raz" << endl;
            break;
        }
    } while(w != 'E');
    
    return 0;
}