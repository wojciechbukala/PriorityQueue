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

    int size = 0;
    std::string sample = "";
    Stack<std::string> s;

    do
    {
        if((charackter = fgetc(file)) == EOF)
        {
            // the last pack can be incomplete, so we complete it with " "
            for(int j=sample.size(); j<pack_size; ++j)
            {
                sample += " ";
            }
            s.push(sample);
            size++;
            break;
        } 
        sample += charackter;
        if(int(sample.size()) == pack_size) // if sample reached the size of the pack 
        {                                   // program sends it to the stack
            s.push(sample);
            sample.clear();
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
    // shuffled array will determine the position of each pack 
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