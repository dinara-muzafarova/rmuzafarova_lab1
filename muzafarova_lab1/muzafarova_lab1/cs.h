#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<float.h>

using namespace std;

class CS
{
public:
    static int max_indexcs;
    CS()
    {
        indexcs = max_indexcs++;
    }
    friend istream& operator>> (istream& in, CS& cs);
    friend ostream& operator<< (ostream& out, CS& cs);
    void editCS();
    //void checkCS();
    //void numberWorkingShops(int max, int& x);
    //void checkEffectiveness();
    void saveCS(ofstream& file);
    void loadCS(ifstream& file);
    int getIdCs() { return indexcs; }
    double get_unused() { return (((double)shop - (double)workingShop) / (double)shop) * 100; }
    string name = "";

    int shop = 0, workingShop = 0;
    int effectiveness = 0;
    int indexcs = 1;
};

