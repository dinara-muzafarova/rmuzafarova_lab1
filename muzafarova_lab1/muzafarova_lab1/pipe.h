#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class pipe
{
public:
    static int max_indexp;
    bool status = 0;
    string name = "";
    pipe()
    {
        indexp = max_indexp++;
    }
    friend istream& operator >> (istream& in, pipe& p);
    friend ostream& operator << (ostream& out, pipe& p);
    void editPipe();
    //void statusPipe();
    int getIdPipe() { return indexp; }
    void savePipe(ofstream& file);
    void loadPipe(ifstream& file);
private:
    double length = 0, diametr = 0;
    int indexp = 1;
};

