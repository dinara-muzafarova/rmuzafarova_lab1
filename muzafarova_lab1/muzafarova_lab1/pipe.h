#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class pipe
{
public:
    static int max_indexp;
    string name = "";
    pipe()
    {
        indexp = max_indexp++;
    }
    friend istream& operator >> (istream& in, pipe& p);
    friend ostream& operator << (ostream& out, pipe& p);
    void editPipe(pipe&p);
    int getIdP() { return indexp; }
    void savePipe(ofstream& file);
    void loadPipe(ifstream& file);
    float length = 0, diametr = 0;
    int status = 0;
    int indexp = 0;
};

