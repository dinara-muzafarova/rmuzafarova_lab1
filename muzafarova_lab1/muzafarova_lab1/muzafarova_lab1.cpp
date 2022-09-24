#include <iostream>
using namespace std;

struct pipe {
	float length = 0, diametr = 0;
	int status = 0;
};

struct CS {
	string name = "";
	int shop = 0, workingShop = 0;
	float effectiveness = 0;
};

void f1(pipe n) {
	if (!n.length) {
		do {
			cout << "  !Error! Input numerical value!\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> n.length;
		} while (!n.length);
	}
}

int main() {
	int operation = -1;
	pipe p;
	CS cs;

	while (operation) {
		cout << "\nChoose operation:\n 1.Add pipe 2.Add CS 3.View all objects 4.Edit pipe 5.Edit CS 6.Save 7.Download 0.Exit\n";
		cin >> operation;
		if (operation == 1) {
			cout << "Input lenght:\n";
			cin >> p.length;
			f1(p);
			cout << "Input diametr:\n";
			cin >> p.diametr;
			f1(p);
			cout << "Choose status of pipe: 1.if repairing, 2.if works";
			cin >> p.status;
			if ((p.status > 2) || (!p.status) || (p.status < 0)) {
				do {
					cout << "!Error! Input numerical value!\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> p.diametr;
				} while ((p.status > 2) || (!p.status) || (p.status < 0));
			}
			if (p.status == 1) {
				cout << "Pipe is repairing\n";
			}
			else {
				cout << "Pipe works\n";
			}
		}
	}
}
