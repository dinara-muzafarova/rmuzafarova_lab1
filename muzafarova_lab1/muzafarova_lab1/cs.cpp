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

int cs::max_indexcs = 0;

istream& operator>>(istream& in, cs& cs)
{
	cout << "Enter the index of the CS: " << cs.indexcs;
	cout << "Enter the name of the CS:\n";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(in, cs.name);
	cout << "Input the number of shops:\n";
	cs.shop = correctNumber(0, INT_MAX);
	cout << "Input the number of working shops:\n";
	cs.workingShop = correctNumber(0, cs.shop);
	cout << "Enter CS efficiency (from 1 to 10)\n";
	cs.effectiveness = correctNumber(0, 10);
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
		cs.workingShop = correctNumber(0, cs.shop);
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
