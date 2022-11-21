#include "pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "header.h"
using namespace std;

int pipe::max_indexp = 0;

string statusPipe(bool x)
{
	if (x == false)
		return("Pipe is repairing\n");
	else if (x == true)
		return("Pipe works\n");
	else
		return("We don't have answer");

}

istream& operator>>(istream& in, pipe& p)
{
	cout << "Enter the index of the pipe: " << p.indexp;
	cout << "Input name:\n";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	cout << "Input lenght:\n";
	p.length = correctNumber(0.0, DBL_MAX);
	cout << "Input diametr:\n";
	p.diametr = correctNumber(0.0, DBL_MAX);
	cout << "Choose status of pipe:\n0.if repairing \n1.if works\n";
	p.status = correctNumber(0,1);
	cout << statusPipe(p.status) << endl;
	return in();
}

ostream& operator<<(ostream& out, pipe& p)
{
	out << "\nIndex of pipe: " << p.indexp << "\nPipe info: " << "\nName: " << p.name << "\nLenght: " << p.length << "\nDiameter : " << p.diametr
		<< "\nStatus: " << statusPipe(p.status) << endl;
	return out;
}

void pipe::editPipe()
{
	if (length != 0) {
		statusPipe(status);
		cout << "\nWrite a new status of pipe: \n0.if repairing \n1.if works" << endl;
		status=correctNumber(1,2);
		statusPipe(status);
	}
	else {
		cout << "You do not have a pipe!" << endl;
	}
}


void pipe::savePipe(ofstream& file)
{
	file << indexp << endl << name << endl << endl << length << endl << diametr << endl << status << endl;
}

void pipe::loadPipe(ifstream& file)
{
	file >> indexp;
	getline(file, name);
	getline(file, name);
	file >> length;
	file >> diametr;
	file >> status;
}
