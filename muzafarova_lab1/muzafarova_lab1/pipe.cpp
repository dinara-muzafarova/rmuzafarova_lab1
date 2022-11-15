#include "pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
using namespace std;

int pipe::max_indexp = 0;

istream& operator>>(istream& in, pipe& p)
{
	cout << "Enter the index of the pipe: " << p.indexp;
	cout << "Input lenght:\n";
	cout << "Input name:\n";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	checkPipe(p.length);
	cout << "Input diametr:\n";
	checkPipe(p.diametr);
	cout << "Choose status of pipe:\n0.if repairing \n1.if works\n";
	checkStatusOfPipe(p.status);
	statusPipe(p);
	return in();
}

ostream& operator<<(ostream& out, pipe& p)
{
	out << "\nIndex of pipe: " << p.indexp << "\nPipe info: " << "\nName: " << p.name << "\nLenght: " << p.length << "\nDiameter : " << p.diametr
		<< "\nStatus: " << statusPipe(p) << endl;
	return out;
}

void pipe::editPipe(pipe& p)
{
	if (p.length != 0) {
		statusPipe(p);
		cout << "\nWrite a new status of pipe: \n0.if repairing \n1.if works" << endl;
		checkStatusOfPipe(p.status);
		statusPipe(p);
	}
	else {
		cout << "You do not have a pipe!" << endl;
	}
}

void pipe::statusPipe(pipe& p)
{
	if (p.status == 0) {
		cout << "Pipe is repairing\n";
	}
	else {
		cout << "Pipe works\n";
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
