#include <iostream>
#include <fstream>
#include <string>
#include "PQueue.hpp"

using namespace std;

int main()
{
    cout << "Odbieranie pakietu." << endl;
    int pack_size, key;
    std::string line, elem, key_str;
    PriorityQueue<std::string> Q;

    ifstream File("buffor.txt");
    if(!File.is_open()) cout << "Nie udalo sie otworzyc pliku" << endl;
    else
    { 
        getline(File,line);
        pack_size = stoi(line);
        //cout << pack_size << endl;

        while(getline(File,line))
        {
            elem = "";
            key_str = "";
            for(int i=0; i<pack_size; ++i)
            {
                elem += line[i];
            }
            for(int i = pack_size; i<int(line.size()); ++i)
            {
                key_str += line[i];
            }
            if(line.size() > 0) key = stoi(key_str);
            Q.push(elem,key);
        }
    }

    cout << "Wiadomosc: " <<endl;

        while(!Q.empty())
        {
            cout << Q.removeMax().getElement();
        } 
        cout << endl << endl;
    

    File.close();


}