#include <iostream>
#include <algorithm>
#include "Stack.hpp"



using namespace std;

/*
std::string convertToString(char* a)
{
    std::string s = a;
    return s;
} */

int main()
{
/*
    Stack<std::string> e;
    e.push("Wojt");
    e.push("Mati");
    e.push("Janu");
    e.push("Marc");
    e.view();
    cout << "Size:" << e.size() << endl; 
    e.remove();
    e.remove();
    e.view();
    cout << "Size:" << e.size() << endl; 
    e.remove();
    e.remove();
    //e.remove();
    e.view();
*/
    srand(time(0));
    int a[8] = {1,2,3,4,5,6,7,8};
    for(int i=0; i<8; ++i) cout << a[i];
    std::random_shuffle(&a[0],&a[7]);
    cout << endl;
    for(int i=0; i<8; ++i) cout << a[i];
    cout << endl;
    return 0;
}