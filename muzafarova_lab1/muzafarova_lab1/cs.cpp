#include "cs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>

using namespace std;

int cs::max_indexcs = 0;

istream& operator>>(istream& in, cs& cs)
{
	cout << "Enter the index of the CS: " << cs.indexcs;
	cout << "Enter the name of the CS:\n";
	getline(cin >> ws, cs.name);
	cout << "Input the number of shops:\n";
	checkCS(cs.shop);
	cout << "Input the number of working shops:\n";
	numberWorkingShops(cs.shop, cs.workingShop);
	cout << "Enter CS efficiency (from 1 to 10)\n";
	checkEffectiveness(cs.effectiveness);
	return in();
}

ostream& operator<<(ostream& out, cs& cs)
{
    out << "Index of CS: " << cs.indexcs << "CS info:\nName: " << cs.name << "\nNumber of workshops: " << cs.shop
		<< "\nNumber of working workshops: " << cs.workingShop << "\nEffectiveness: "
		<< cs.effectiveness << endl;
	return out();
}

void cs::editCS(cs& cs)
{
	if (cs.shop != 0) {
		cout << "The number of shops: ";
		cout << cs.shop << endl;
		cout << "The number of working shops: ";
		cout << cs.workingShop << endl;
		cout << "\nWrite a new number of working shops:" << endl;
		numberWorkingShops(cs.shop, cs.workingShop);
	}
	else {
		cout << "You do not have a CS!" << endl;
	}
}

void cs::saveCS(ofstream& file)
{
	file << indexcs << endl << name << endl << shop << endl << workingShop << endl << effectiveness << endl;
}

void cs::loadCS(ifstream& file)
{
	file >> indexcs;
	getline(file, name);
	file >> shop;
	file >> workingShop;
	file >> effectiveness;
}
