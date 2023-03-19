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