#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<float.h>

using namespace std;

class cs
{
public:
    static int max_indexcs;
    cs()
    {
        indexcs = max_indexcs++;
    }
    friend istream& operator>> (istream& in, cs& cs);
    friend ostream& operator<< (ostream& out, cs& cs);
    void editCS(cs& cs);
    void checkCS();
    void numberWorkingShops();
    void checkEffectiveness();
    void saveCS(ofstream& file);
    void loadCS(ifstream& file);
    int getIdCs() { return indexcs; }
    double get_unused() { return (((double)shop - (double)workingShop) / (double)shop) * 100; }
    string name = "";

    int shop = 0, workingShop = 0;
    int effectiveness = 0;
    int indexcs = 0;
};

