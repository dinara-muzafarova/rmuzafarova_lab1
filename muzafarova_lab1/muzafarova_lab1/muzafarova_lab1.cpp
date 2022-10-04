#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//параметры трубы
struct pipe {
	float length = 0, diametr = 0;
	int status = 0;
	bool existence = 0;
};

//параметры КС
struct CS {
	string name = "";
	double shop = 0, workingShop = 0;
	double effectiveness = 0;
	bool existence = 0;
};

//проверка целочисленных данных
double checkCS(double x) {
	while ((x / trunc(x) != 1) || (x < 0)) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> x;
	}
	return x;
}

double checkPipe(double x) {
	while (x <= 0) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> x;
	}
	return x;
}

int checkStatusOfPipe(int x) {
	while ((x < 0) || (x > 1)) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> x;
	}
	return x;
}

//проверка эффективности КС
int checkEffectiveness(int x) {
	while ( (x < 1) || (x > 10)) {
		cout << "Error!\nInput value from 1 to 10!\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> x;
	}
	return x;
}

//менюшка
void menu() {
	cout << "\nChoose operation:" << endl
		<< " 1.Add pipe" << endl
		<< " 2.Add CS" << endl
		<< " 3.View all objects" << endl
		<< " 4.Edit pipe" << endl
		<< " 5.Edit CS" << endl
		<< " 6.Save" << endl
		<< " 7.Download" << endl
		<< " 0.Exit" << endl;
}

//сохранение файлов блокнот
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
	cout << "The data is saved." << endl;
}

//выгрузка файлов из блокнота
void loadData(pipe& p, CS& cs) {
	ifstream fin;
	string line;
	fin.open("data.txt");
	fin >> p.length;
	fin >> p.diametr;
	fin >> p.status;
	p.existence = 1;
	getline(fin, line);
	cs.name = line;
	fin >> cs.shop;
	fin >> cs.workingShop;
	fin >> cs.effectiveness;
	cs.existence = 1;
	fin.close();
	cout << "The data is uploaded." << endl;
}

//статус работы трубы
void statusPipe(pipe& p) {
	if (p.status == 0) {
		cout << "Pipe is repairing\n";
	}
	else {
		cout << "Pipe works\n";
	}
}

//добавление трубы
void addPipe(pipe& p) {
	cout << "Input lenght:\n";
	cin >> p.length;
	checkPipe(p.length);
	cout << "Input diametr:\n";
	cin >> p.diametr;
	checkPipe(p.diametr);
	cout << "Choose status of pipe:\n0.if repairing \n1.if works\n";
	cin >> p.status;
	checkStatusOfPipe(p.status);
	statusPipe(p);
	p.existence = true;
}

//редактирование трубы
void editPipe(pipe& p) {
	if (p.existence) {
		statusPipe(p);
		cout << "\nWrite a new status of pipe: \n0.if repairing \n1.if works" << endl;
		cin >> p.status;
		checkStatusOfPipe(p.status);
		statusPipe(p);
	}
	else {
		cout << "You do not have a pipe!" << endl;
	}
}

//проверка (количество рабочих цехов не может быть больше всех)
void numberWorkingShops(CS& cs) {
	if (cs.workingShop > cs.shop) {
		do {
			cout << "Error!\nThe number of working shops cannot exceed the number of all shops!!!\n";
			cin >> cs.workingShop;
		} while (cs.workingShop > cs.shop);
	}
}

//добавление КС
void addCS(CS& cs) {
	cout << "Enter the name of the CS:\n";
	cin >> cs.name;
	cout << "Input the number of shops:\n";
	cin >> cs.shop;
	checkCS(cs.shop);
	cout << "Input the number of working shops:\n";
	cin >> cs.workingShop;
	checkCS(cs.workingShop);
	numberWorkingShops(cs);
	cout << "Enter CS efficiency (from 1 to 10)\n";
	cin >> cs.effectiveness;
	checkEffectiveness(cs.effectiveness);
	cs.existence = true;
}

//редактирование КС
void editCS(CS& cs) {
	if (cs.existence) {
		cout << "The number of shops: ";
		cout << cs.shop << endl;
		cout << "The number of working shops: ";
		cout << cs.workingShop << endl;
		cout << "\nWrite a new number of working shops:" << endl;
		cin >> cs.workingShop;
		checkCS(cs.workingShop);
		numberWorkingShops(cs);
	}
	else {
		cout << "You do not have a CS!" << endl;
	}
}

//просмотр всех объектов
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
		cout << "\nCS efficiency: " << cs.effectiveness << endl;
	}
	else {
		cout << "\nThe CS does not exist!" << endl;
	}
}

//основная часть (бади)
int main() {
	int operation = -1;
	pipe p;
	CS cs;
	while (true) {
		menu();
		cin >> operation;
		checkCS(operation);
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
