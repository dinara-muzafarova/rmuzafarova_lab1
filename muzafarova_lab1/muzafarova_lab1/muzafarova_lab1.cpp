#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct pipe {
	float length = 0, diametr = 0;
	bool status = 0;
	bool existence = 0;
};

struct CS {
	string name = "";
	int shop = 0, workingShop = 0;
	int effectiveness = 0;
	bool existence = 0;
};

template <typename T>
void check(T& input)
{
	while ((cin >> input).fail() || input < 0) {
		cout << "Error!\nInput correct value!\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

template <typename T>
void checkEffectiveness(T& input) {
	while ((cin >> input).fail() || input < 1 || input > 10) {
		cout << "Error!\nInput value from 1 to 10!\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
void menu() {
	cout << "\nChoose operation:" << endl
		<< "1.Add pipe" << endl
		<< "2.Add CS" << endl
		<< "3.View all objects" << endl
		<< "4.Edit pipe" << endl
		<< "5.Edit CS" << endl
		<< "6.Save" << endl
		<< "7.Download" << endl
		<< "0.Exit" << endl;
}

void saveData(pipe& p,CS& cs) {
	ofstream fout;
	fout.open("data.txt", 'w');
	fout << p.length << endl
		<< p.diametr << endl
		<< p.status << endl
		<< cs.name << endl
		<< cs.shop << endl
		<< cs.workingShop << endl
		<< cs.effectiveness << endl;
	fout.close();
}

void loadData(pipe& p, CS& cs) {
	ifstream fin;
	string line;
	fin.open("data.txt");
	getline(fin, line);
	p.length = stoi(line);
	getline(fin, line);
	p.diametr = stoi(line);
	getline(fin, line);
	p.status = stoi(line);
	getline(fin, line);
	cs.name = line;
	getline(fin, line);
	cs.shop = stoi(line);
	getline(fin, line);
	cs.workingShop = stoi(line);
	getline(fin, line);
	cs.effectiveness = stoi(line);
	fin.close();
}

void statusPipe(pipe& p) {
	if (p.status == 0) {
		cout << "Pipe is repairing\n";
	}
	else {
		cout << "Pipe works\n";
	}
}

void addPipe(pipe& p) {
	cout << "Input lenght:\n";
	check(p.length);
	cout << "Input diametr:\n";
	check(p.diametr);
	cout << "Choose status of pipe:\n0.if repairing \n1.if works\n";
	check(p.status);
	statusPipe(p);
	p.existence = true;
}

void editPipe(pipe& p) {
	if (p.existence) {
		statusPipe(p);
		cout << "Write a new status of pipe: \n0.if repairing \n1.if works" << endl;
		check(p.status);
		statusPipe(p);
	}
	else {
		cout << "You do not have a pipe!" << endl;
	}
}

void numberWorkingShops(CS& cs) {
	if (cs.workingShop > cs.shop) {
		do {
			cout << "Error!\nThe number o f working shops cannot exceed the number of all shops!!!\n";
			cin >> cs.workingShop;
		} while (cs.workingShop > cs.shop);
	}
}
void addCS(CS& cs) {
	cout << "Enter the name of the CS:\n";
	cin >> cs.name;
	cout << "Input the number of shops:\n";
	check(cs.shop);
	cout << "Input the number of working shops:\n";
	check(cs.workingShop);
	numberWorkingShops(cs);
	cout << "Enter CS efficiency (from 1 to 10)\n";
	checkEffectiveness(cs.effectiveness);
	cs.existence = true;
}

void editCS(CS& cs) {
	if (cs.existence) {
		cout << "The number of shops: ";
		cout << cs.shop << endl;
		cout << "The number of working shops: ";
		cout << cs.workingShop << endl;
		cout << "Write a new number of working shops:" << endl;
		check(cs.workingShop);
		numberWorkingShops(cs);
	}
	else {
		cout << "You do not have a CS!" << endl;
	}
}

void viewAll(pipe p, CS cs) {
	if (p.existence) {
		cout << "Pipe:\n";
		cout << "length: " << p.length;
		cout << "\ndiametr: " << p.diametr;
		cout << "\nstatus: "; statusPipe(p);
	}
	else {
		cout << "\nThe pipe does not exist!";
	}
	if (cs.existence) {
		cout << "\nCS:";
		cout << "\nName: " << cs.name;
		cout << "\nThe number of shops: " << cs.shop;
		cout << "\nThe number of working shops: " << cs.workingShop;
		cout << "\nCS efficiency: " << cs.effectiveness;
	}
	else {
		cout << "\nThe CS does not exist!" << endl;
	}
}
int main() {
	int operation = -1;
	pipe p;
	CS cs;
	while (true) {
		menu();
		cin >> operation;
		switch (operation) {
			//добавление трубы
		case 1: {
			addPipe(p);
			break;
		}
			  //добавление КС
		case 2: {
			addCS(cs);
			break;
		}
		case 3: {
			viewAll(p, cs);
			break;
		}
		case 4: {
			editPipe(p);
			break;
		}
		case 5: {
			editCS(cs);
			break;
		}
		case 6: {
			saveData(p, cs);
			break;
		}
		case 7: {
			loadData(p, cs);
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "Error!\nInput correct value!\n";
		}
		}
	}
}
