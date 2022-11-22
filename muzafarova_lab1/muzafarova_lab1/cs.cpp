#include "cs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "header.h"

using namespace std;

int CS::max_indexcs = 1;

istream& operator>>(istream& in, CS& cs)
{
	cout << "Index of the CS: " << cs.indexcs << endl;
	cout << "Enter the name of the CS: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(in, cs.name);
	cout << "Input the number of shops: ";
	cs.shop = correctNumber(0, INT_MAX);
	cout << "Input the number of working shops: ";
	cs.workingShop = correctNumber(0, cs.shop);
	cout << "Enter CS efficiency (from 0 to 10): ";
	cs.effectiveness = correctNumber(0, 10);
	return in;
}

ostream& operator<<(ostream& out, CS& cs)
{
    out << "Index of CS: " << cs.indexcs << "\nCS info:\nName: " << cs.name << "\nNumber of workshops: " << cs.shop
		<< "\nNumber of working workshops: " << cs.workingShop << "\nEffectiveness: "
		<< cs.effectiveness << endl;
	return out;
}

void CS::editCS()
{
	if (shop != 0) {
		cout << "ID of CS: " << indexcs << endl;
		cout << "The number of shops: ";
		cout << shop << endl;
		cout << "The number of working shops: ";
		cout << workingShop << endl;
		cout << "\nWrite a new number of working shops:" << endl;
		workingShop = correctNumber(0, shop);
	}
	else {
		cout << "You do not have a CS!" << endl;
	}
}

void CS::saveCS(ofstream& fout)
{
	fout << indexcs << endl << name << endl << shop << endl << workingShop << endl << effectiveness << endl;
}

void CS::loadCS(ifstream& fin)
{
	fin >> indexcs;
	getline(fin, name);
	getline(fin, name);
	fin >> shop;
	fin >> workingShop;
	fin >> effectiveness;
}


