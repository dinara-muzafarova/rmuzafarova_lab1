﻿#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include "pipe.h"
#include "cs.h"
#include <unordered_map>
#include <unordered_set>
#include "header.h"

using namespace std;

unordered_map<int, pipe> pipe_group;
unordered_map<int, CS> cs_group;
unordered_set<int> idpipe;
unordered_set <int> idcs;

ostream& operator<<(ostream& out, unordered_set <int>& par) {
	out << "Exiting id: ";
	for (auto& i : par) {
		out << i << " ";
	}
	out << endl;
	return out;
}

bool checkPipeName(pipe& p, string name) {
	return (p.name.find(name) != string::npos);
}

bool checkPipeStatus(pipe& p, bool status) {
	return (p.status == status);
}

bool checkCSName(CS& cs, string name) {
	return(cs.name.find(name) != string::npos);
}

bool checkUnworking(CS& cs, double p) {
	return(cs.get_unused() >= p);
}

void viewAll(unordered_map<int, pipe>&pipe_group, unordered_map<int, CS>& cs_group) {
	if (pipe_group.size() != 0) {
		for (auto& pipe : pipe_group) {
			cout << pipe.second << endl;
		}
	}
	else {
		cout << "You don't have pipes!" << endl;
	}
	if (cs_group.size() != 0) {
		for (auto& CS : cs_group) {
			cout << CS.second << endl;
		}
	}
	else {
		cout << "You don't have CSs!" << endl;
	}
}

vector <int> searchPipe(unordered_map<int, pipe>pipe_group) {
	vector<int> idp;
	int x;
	cout << "Search pipe by: 1.name 2.status" << endl;
	x = correctNumber(1, 2);
	if (x == 1) {
		string name;
		cout << "Enter the name of pipe: " << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, name);
		idp = parametr_p(pipe_group, checkPipeName, name);
	}
	else {
		bool n;
		cout << "Enter the status of pipe(0 or 1): " << endl;
		n = correctNumber(0, 1);
		idp = parametr_p(pipe_group, checkPipeStatus, n);
	}
	return idp;
}

vector<int>searchCS(unordered_map<int, CS>& cs_group) {
	int x;
	vector <int> idcs;
	cout << "Search CS by: 1.name 2.% of unused shops" << endl;
	x = correctNumber(1, 2);
	if (x == 1) {
		string name;
		cout << "Enter the name of CS: " << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, name);
		idcs = parametr_cs(cs_group, checkCSName, name);
	}
	else {
		double n;
		cout << "Enter the % of unused shops: " << endl;
		n = correctNumber(0, 100);
		idcs = parametr_cs(cs_group, checkUnworking, n);
	}
	return idcs;
}

void addPipe() {
	idpipe.insert(pipe::max_indexp);
	pipe p;
	cin >> p;
	pipe_group.insert({ p.getIdPipe(),p });
}

void addCS() {
	idcs.insert(pipe::max_indexp);
	CS cs;
	cin >> cs;
	cs_group.insert({ cs.getIdCs(),cs });
}

void editPipes(unordered_map<int,pipe>& pipe_group) {
	int edit;
	int id;
	int x;
	if (pipe_group.size() != 0) {
		cout << "1.Choose 1 pipe \n2.Choose pipes \n3.Delete pipe" << endl;
		edit = correctNumber(1, 3);
		if (edit == 1) {
			cout << "Choose pipe to edit: " << endl;
			for (auto& pipe : pipe_group) {
				cout << pipe.second << endl;
			}
			id = correctNumber(0, (int)pipe_group.size());
			if (pipe_group.find(id) != pipe_group.end()) {
				pipe_group[id].editPipe();
			}
			else {
				cout << "You don't have such pipe!" << endl;
			}
		}
		if (edit == 2) {
			bool n;
			vector <int> indexp;
			cout << "Choose pipes by 1.filter 2.id" << endl;
			x = correctNumber(1, 2);
			if (x == 1) {
				auto idp=searchPipe(pipe_group);
				if (idp.size() != 0) {
					cout << "Enter a new status of pipe: " << endl;
					n = correctNumber(0, 1);
					for (auto& i : idp)
						pipe_group[i].status = n; 
				}
				else {
					cout << "You don't have such pipe!" << endl;
				}
			}
			if (x == 2) {
				int n;
				int id;
				unordered_set <int> ids;
				for (auto& pipe : pipe_group) {
					cout << pipe.second << endl;
				}
				cout << "Enter the number of id of pipes you want to edit: " << endl;
				n = correctNumber(1, (int)pipe_group.size());
				cout << "Enter id of pipes: " << endl;
				for (int i = 0; ids.size() < n; i++) {
					id = correctNumber(0, pipe::max_indexp - 1);
					if (pipe_group.find(id) != pipe_group.end()) {
						ids.insert(id);
					}
					else {
						cout << "You don't have such pipe!" << endl;
					}
				}
				cout << "Enter a new status of pipe: " << endl;
				n = correctNumber(0, 1);
				for (auto& i : ids)
					pipe_group[i].status = n;
			}
		}
		if (edit == 3) {
			int k;
			int n;
			cout << "You want to delete:\n1.one pipe \n2. more than one pipe" << endl;
			k = correctNumber(1, 2);
			if (k == 1) {
				for (auto& pipe : pipe_group) {
					cout << pipe.second << endl;
				}
				cout << "Enter the id of pipe you want to delete: ";
				n = correctNumber(0, pipe::max_indexp - 1);
				while (pipe_group.find(n) == pipe_group.end()) {
					cout << "You don't have such pipe!" << endl;
					n = correctNumber(0, pipe::max_indexp - 1);
				}
				pipe_group.erase(pipe_group.find(n));
			}
			else {
				unordered_set <int> ids;
				cout << "Delete by: 1.filter 2.id" << endl;
				int d = correctNumber(1, 2);
				if (d == 1) {
					auto idp = searchPipe(pipe_group);
					if (idp.size() != 0) {
						for (auto& i : idp) {
							pipe_group.erase(pipe_group.find(i));
						}
					}
					else {
						cout << "You don't have such pipe!";
					}
				}
				else {
					for (auto& pipe : pipe_group) {
						cout << pipe.second << endl;
					}
					cout << "Enter the number of pipe you want to delete: ";
					int n = correctNumber(1, (int)pipe_group.size());
					cout << "Enter id of pipes: ";
					while (ids.size() < n) {
						int s = correctNumber(0, pipe::max_indexp - 1);
						if (pipe_group.find(s) != pipe_group.end()) {
							ids.insert(s);
						}
						else {
							cout << "You don't have such pipe!";
						}
					}
					for (auto& id : ids) {
						pipe_group.erase(pipe_group.find(id));
					}
				}
			}
		}
	}
	else {
	cout << "You don't have pipe to edit!" << endl;
}
}

void editCSs(unordered_map<int, CS>& cs_group) {
	vector <int> ids;
	int edit;
	int id;
	int x;
	if (cs_group.size() != 0) {
		cout << "1.Choose 1 CS \n2.Choose CS(>1) \n3.Delete CS" << endl;
		edit = correctNumber(1, 3);
		if (edit == 1) {
			for (auto& CS : cs_group) {
				cout << CS.second << endl;
			}
			cout << "Choose CS to edit: " << endl;
			id = correctNumber(0, (int)cs_group.size());
			if (cs_group.find(id) != cs_group.end()) {
				cs_group[id].editCS();
			}
			else {
				cout << "You don't have such pipe!" << endl;
			}
		}
		if (edit == 2) {
			bool n;
			unordered_set <int> idk;
			cout << "Choose CS by 1.filter 2.id" << endl;
			x = correctNumber(1, 2);
			if (x == 1) {
				auto idp = searchCS(cs_group);
				if (idp.size() != 0) {
					cout << "Enter a new status of pipe: " << endl;
					n = correctNumber(0, 1);
					for (auto& i : idp)
						cs_group[i].editCS();
				}
				else {
					cout << "You don't have such pipe!" << endl;
				}
			}
			if (x == 2) {
				int n;
				int y;
				for (auto& CS : cs_group) {
					cout << CS.second << endl;
				}
				cout << "Enter the number of CSs you want to edit: " << endl;
				n = correctNumber(1, (int)cs_group.size());
				cout << "Enter id of CSs: " << endl;
				for (int i = 0; idk.size() < n; i++) {
					cin >> y;
					if (cs_group.find(y) != cs_group.end()) {
						idk.insert(y);
					}
					else {
						cout << "You don't have such CS!" << endl;
					}
				}
				for (auto& i : idk)
					cs_group[i].editCS();
			}
		}
		if (edit == 3) {
			int k;
			int n;
			cout << "You want to delete:\n1.one CS \n2. more than one CS: " << endl;
			k = correctNumber(1, 2);
			if (k == 1) {
				for (auto& CS : cs_group) {
					cout << CS.second << endl;
				}
				cout << "Enter the id of CS you want to delete: ";
				n = correctNumber(0, CS::max_indexcs - 1);
				while (cs_group.find(n) == cs_group.end()) {
					cout << "You don't have such CS!" << endl;
					n = correctNumber(0, CS::max_indexcs - 1);
				}
				cs_group.erase(cs_group.find(n));
			}
			else {
				unordered_set <int> ids;
				cout << "Delete by: 1.filter 2.id" << endl;
				int d = correctNumber(1, 2);
				if (d == 1) {
					auto idp = searchCS(cs_group);
					if (idp.size() != 0) {
						for (auto& i : idp) {
							cs_group.erase(cs_group.find(i));
						}
					}
					else {
						cout << "You don't have such pipe!";
					}
				}
				else {
					for (auto& CS : cs_group) {
						cout << CS.second << endl;
					}
					cout << "Enter the number of CS you want to delete: ";
					int n = correctNumber(1, (int)cs_group.size());
					cout << "Enter id of CSs: ";
					for(int i = 0; i < n; i++) {
						int s = correctNumber(0, CS::max_indexcs);
						if (cs_group.find(s) !=cs_group.end()) {
							ids.insert(s);
						}
						else {
							i = i - 1;
							cout << "You don't have such CS!";
						}
					}
					for (auto& i : ids) {
						cs_group.erase(cs_group.find(i));
					}
				}
			}
		}
	}
	else {
		cout << "You don't have CS to edit!" << endl;
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
		<< " 8.Search pipe" << endl
		<< " 9.Search CS" << endl
		<< " 0.Exit" << endl;
}

//основная часть (бади)
int main() {
	int operation = -1;
	unordered_map<int, pipe> pipe_group;
	unordered_map<int, CS> cs_group;
	while (true) {
		menu();
		operation = correctNumber(0,9);
		switch (operation) {
		//добавление трубы
		case 1: {
			pipe p;
			cin >> p;
			pipe_group.insert({ p.getIdPipe(),p });
			break;
		}
		//добавление КС
		case 2: {
			CS cs;
			cin >> cs;
			cs_group.insert({ cs.getIdCs(),cs });
			break;
		}
		//просмотр всех объектов
		case 3: {
			viewAll(pipe_group, cs_group);
			break;
		}
		// редактирование статуса трубы
		case 4: {
			editPipes(pipe_group);
			break;
		}
		// редактирование количества рабочих цехов
		case 5: {
			editCSs(cs_group);
			break;
		}
		// сохранение данных в блокнот
		case 6: {
			string x;
			cout << "Enter the name of file " << endl;
			cin >> x;
			ofstream file;
			//file.open();
			if (!file) {
				cout << "ERROR!" << endl;
			}
			else {
				file << pipe_group.size() << " " << cs_group.size() << endl;
				for (auto pipe : pipe_group)
					pipe.second.savePipe(file);
				for (auto CS : cs_group)
					CS.second.saveCS(file);
			}
			break;
		}
		// выгрузка данных из блокнота
		case 7: {
			string x;
			int l1, l2;
			pipe newp;
			CS newcs;
			cout << "Enter the name of file: ";
			cin >> x;
			ifstream file;
			//file.open();
			if (!file) {
				cout << "ERROR!" << endl;
			}
			else {
				pipe::max_indexp = 0;
				CS::max_indexcs = 0;
				pipe_group.clear();
				cs_group.clear();
				file >> l1 >> l2;
				for (int i = 0; i < l1; i++) {
					newp.loadPipe(file);
					pipe_group.insert({ newp.getIdPipe(),newp });
					if (pipe::max_indexp <= newp.getIdPipe()) {
						pipe::max_indexp = newp.getIdPipe() + 1;
					}
				}
				for (int i = 0; i < l2; i++) {
					newcs.loadCS(file);
					cs_group.insert({ newcs.getIdCs(),newcs });
					if (CS::max_indexcs <= newcs.getIdCs()) {
						CS::max_indexcs = newcs.getIdCs() + 1;
					}
				}
			}
			break;
		}
		case 8: {
			if (pipe_group.size() != 0) {
				auto p = searchPipe(pipe_group);
				if (p.size() != 0) {
					for (auto& i : p)
						cout << pipe_group[i] << endl;
				}
				else {
					cout << "You don't have such pipe!" << endl;
				}
			}
			else {
				cout << "You don't have a pipe!" << endl;
			}
			break;
		}
		case 9: {
			if (cs_group.size() != 0) {
				auto c = searchCS(cs_group);
				if (c.size() != 0) {
					for (auto& i : c)
						cout << cs_group[i] << endl;
				}
				else {
					cout << "You don't have such CS!" << endl;
				}
			}
			else {
				cout << "You don't have a CS!" << endl;
			}
			break;
		}
		// выход 
		case 0: {
			return 0;
		}
		default: {
			cout << "Error!\nInput correct value!\n";
			break;
		}
		}
	}
}
