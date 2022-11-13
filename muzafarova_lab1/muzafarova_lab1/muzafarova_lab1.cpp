#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//параметры трубы
class pipe {
public:
	 int p_index;
	float length = 0, diametr = 0;
	int status = 0;
};

//параметры КС
struct CS {
	string name = "";
	int shop = 0, workingShop = 0;
	int effectiveness = 0;
};

//проверка целочисленных данных
void checkCS(int& x) {
	while ((cin >> x).fail() || (x / trunc(x) != 1) || (x < 0) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

//проверка целочисленных данных для меню и рабочих цехов
void checkMenu(int& x) {
	while ((cin >> x).fail() || (x < 0) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

//проверка параметров трубы
void checkPipe(float& x) {
	while (((cin >> x).fail()) ||(x <= 0) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

//проверка статуса трубы
void checkStatusOfPipe(int& x) {
	while (((cin >> x).fail())||(x < 0) || (x > 1) || (cin.peek() != '\n')) {
		cout << "Error! Input correct value!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

//проверка эффективности КС
void checkEffectiveness(int& x) {
	while (((cin >> x).fail()) || (x < 1) || (x > 10) || (cin.peek() != '\n')) {
		cout << "Error!\nInput value from 1 to 10!\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
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
	if (p.length != 0) {
		fout << "1" << endl
			<< p.length << endl
			<< p.diametr << endl
			<< p.status << endl;
	}
	else {
		fout << "0" << endl;
	}
	if (cs.shop != 0) {
		fout << "1" << endl
			<< cs.name << endl
			<< cs.shop << endl
			<< cs.workingShop << endl
			<< cs.effectiveness << endl;
	}
	else {
		fout << "0" << endl;
	}
	fout.close();
	cout << "The data is saved." << endl;
}

//выгрузка файлов из блокнота
void loadData(pipe& p, CS& cs) {
	ifstream fin;
	string line;
	int exist;
	fin.open("data.txt");
	fin >> exist;
	if (exist == 1) {
		fin >> p.length;
		fin >> p.diametr;
		fin >> p.status;
	}
	fin >> exist;
	if (exist == 1) {
		getline(fin >> ws, cs.name);
		fin >> cs.shop;
		fin >> cs.workingShop;
		fin >> cs.effectiveness;
	}
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

pipe& selectPipe(vector<pipe>& g) {
	cout << "Enter index: ";
	int index;
	cin >> index;
	return g[index - 1];
}

//добавление трубы
void addPipe(pipe& p) {
	cout << "Input lenght:\n";
	checkPipe(p.length);
	cout << "Input diametr:\n";
	checkPipe(p.diametr);
	cout << "Choose status of pipe:\n0.if repairing \n1.if works\n";
	checkStatusOfPipe(p.status);
	statusPipe(p);
}

//редактирование трубы
void editPipe(pipe& p) {
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

//проверка (количество рабочих цехов не может быть больше всех)
void numberWorkingShops(int max,int& x) {
	while (((cin >> x).fail()) || (x<0) ||(x > max)) {
			cout << "Error!\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
	}
}

//добавление КС
void addCS(CS& cs) {
	cout << "Enter the name of the CS:\n";
	getline(cin>>ws, cs.name);
	cout << "Input the number of shops:\n";
	checkCS(cs.shop);
	cout << "Input the number of working shops:\n";
	numberWorkingShops(cs.shop,cs.workingShop);
	cout << "Enter CS efficiency (from 1 to 10)\n";
	checkEffectiveness(cs.effectiveness);
}

//редактирование КС
void editCS(CS& cs) {
	if (cs.shop != 0) {
		cout << "The number of shops: ";
		cout << cs.shop << endl;
		cout << "The number of working shops: ";
		cout << cs.workingShop << endl;
		cout << "\nWrite a new number of working shops:" << endl;
		numberWorkingShops(cs.shop,cs.workingShop);
	}
	else {
		cout << "You do not have a CS!" << endl;
	}
}

//просмотр всех объектов
void viewAll(pipe p, CS cs) {
	if (p.length != 0) {
		cout << "Pipe:\n";
		cout << "length: " << p.length;
		cout << "\ndiametr: " << p.diametr;
		cout << "\nstatus: "; statusPipe(p);
	}
	else {
		cout << "\nThe pipe does not exist!";
	}
	if (cs.shop != 0) {
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
		checkMenu(operation);
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
		//просмотр всех объектов
		case 3: {
			viewAll(p, cs);
			break;
		}
		// редактирование статуса трубы
		case 4: {
			editPipe(p);
			break;
		}
		// редактирование количества рабочих цехов
		case 5: {
			editCS(cs);
			break;
		}
		// сохранение данных в блокнот
		case 6: {
			saveData(p, cs);
			break;
		}
		// выгрузка данных из блокнота
		case 7: {
			loadData(p, cs);
			break;
		}
		// выход 
		case 0: {
			return 0;
		}
		default: {
			cout << "Error!\nInput correct value!\n";
		}
		}
	}
}
