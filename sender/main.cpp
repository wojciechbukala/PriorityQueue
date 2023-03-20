#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include "Stack.hpp"


using namespace std;



int main()
{
    int pack_size = 0;
    std::string file_name;

    cout << "Podaj wielkosc pakietow" << endl;
    cin >> pack_size;

    char charackter;

    cout << "Podaj nazwe pliku do odczytu" <<endl;
    cin >> file_name; 

    FILE* file;
    file = fopen(file_name.c_str(), "r");
    if (file == NULL) cout << "Error opening file" << endl;

    int i = 0, size = 0;
    std::string sample = "";
    Stack<std::string> s;

    do
    {
        charackter = fgetc(file);
        sample += charackter;
        ++i;
        if(i == pack_size) 
        {
            s.push(sample);
            sample = "";
            i = 0;
            size++;
        }
    } while(charackter != EOF);

    fclose(file);

    std::string Content[size];
    int Keys[size];


    int RandOrder[size];
    srand(time(0));
    for(int i=0; i<size; ++i) 
    {
        RandOrder[i] = i;
    }
    std::random_shuffle(&RandOrder[0],&RandOrder[size]); 

    int a = 0;
    while(!s.empty())
    {

        Content[RandOrder[a]] = s.remove().getElement();
        Keys[RandOrder[a]] = a;
        a++;
    }

    std::ofstream TxtFile;
    TxtFile.open ("buffor.txt");
    TxtFile << pack_size << std::endl; 
    for(int i=0; i<size; ++i)
    {
        TxtFile << Content[i] << " " << Keys[i] << std::endl;
    }
    

    cout << "Sending." << endl;


    return 0;
}