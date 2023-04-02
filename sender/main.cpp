#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <sys/stat.h>
#include "Stack.hpp"


using namespace std;

int main()
{
    int pack_size = 0;
    std::string file_name;

    cout << "Podaj wielkosc pakietow" << endl;
    cin >> pack_size;

    cout << "Podaj nazwe pliku do odczytu" <<endl;
    cin >> file_name; 


    std::ifstream infile;

    int size = 0;
    char charackter;
    std::string buffer="";

    Stack<std::string> stack;

    infile.open(file_name);
    if(infile.good())
    {
        while(!infile.eof())
        {
            for(int i=0;((!infile.eof()) && i<pack_size);++i)
            {
                infile.get(charackter);
                buffer +=charackter ;
            }
            stack.push(buffer);
            buffer.clear();
            ++size;
        }
    infile.close();
        
    }
    else
    {
        cout << "brak pliku" << endl;
    }
    std::string Content[size];
    int Keys[size];

    int RandOrder[size];
    srand(time(0));
    for(int i=0; i<size; ++i)
    {
        RandOrder[i] = i;
    }
    //suffled array will determine the position of each pack
    std::random_shuffle(&RandOrder[0],&RandOrder[size]);
    

    int a = 0;
    while(!stack.empty())
    {
        Content[RandOrder[a]] = stack.remove().getElement();
        Keys[RandOrder[a]] = a;
        ++a;
    }


    mkdir("buffer", 0777);
    std::string folder = "buffer/";

    std::ofstream BuffFile;
    BuffFile.open(folder+"file");
    BuffFile << size;
    BuffFile.close();
    
    for(int i=0; i<size; ++i)
    {
        BuffFile.open(folder+"file"+to_string(i));
        BuffFile << Content[i] << endl;
        BuffFile << Keys[i];
        BuffFile.close();
    }

    cout << "Sending." << endl;

    return 0;
}