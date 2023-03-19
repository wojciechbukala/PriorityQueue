#include <iostream>
#include <stdio.h>
#include <fstream>
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

    int i = 0, a = 0;
    std::string sample = "";
    Stack<std::string> s;

    do
    {
        charackter = fgetc(file);
        sample += charackter;
        //cout << charackter[i];
        ++i;
        if(i == pack_size) 
        {
            //sample = charackter;
            //cout << charackter << endl;
            s.push(sample);
            sample = "";
            i = 0;
        }
    } while(charackter != EOF);

    fclose(file);

    //s.view();

    int sample_key = 1;
    std::ofstream CsvFile;
    CsvFile.open ("buffor.csv");
    while(!s.empty())
    {
        CsvFile << s.remove().getElement() << "," << sample_key << std::endl;
        sample_key++;
    }
    

    cout << "Sending." << endl;


    return 0;
}