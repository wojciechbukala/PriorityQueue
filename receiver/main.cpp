#include <iostream>
#include <fstream>
#include <string>
#include "PQueue.hpp"

using namespace std;

int main()
{
    PriorityQueue<std::string> q;

    char charackter;
    std::string elem = "";

    std::ifstream buffer_file;
    buffer_file.open("buffer/file");

    while(buffer_file.get(charackter))
    { 
        elem+=charackter;   
    }
    int folder_size = stoi(elem);
    elem.clear();
    buffer_file.close();

    for(int i=0; i<folder_size; ++i)
    {
        buffer_file.open("buffer/file"+to_string(i));

        if(buffer_file.good())
        {
            while(!buffer_file.eof())
            {
                buffer_file.get(charackter);
                elem += charackter;
            }
        }
        buffer_file.close();

        //finding key which should be in the last line of the elem string
        size_t position = elem.find_last_of('\n');

        if(position != std::string::npos)
        {
            //dividing into info and key, pushing to the priority queue
            q.push(elem.substr(0, position), std::stoi(elem.substr(position + 1)));
        }
        elem.clear();
    }

    std::string out_file = "";
    cout << "Podaj plik do zapisu: " <<endl;
    cin >> out_file;

    std::ofstream output_file;
    output_file.open(out_file);

    if(output_file.good())
    {
        while(!q.empty())
        {
            output_file << q.removeMax().getElement();
        }
    }
    else
    {
        cout << "Blad pliku" << endl;
    }
    output_file.close();

    cout << "Zapisano wiadomosc w: " << out_file << endl; 
/*
    while(!q.empty())
    {
        cout << q.removeMax().getElement();
    } 
*/

    return 0;


}