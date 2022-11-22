#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include "cs.h"
#include "pipe.h"
#include <unordered_map>
#include <unordered_set>


using namespace std;

template <typename T>
T correctNumber(T min, T max) {
	T x;
	while ((cin >> x).fail() || (x < min) || (x > max) || (cin.peek() != '\n')) {
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout << "Error!!! Input correct value!" << endl;
	}
	return x;
}
template <typename T> 
using filter_pipe = bool (*) (pipe& p, T par);

template <typename T>
using filter_cs = bool (*) (CS& cs, T par);

template <typename T>
vector <int> findPipeByParametr(unordered_map <int, pipe>& pipe_group, filter_pipe<T> f, T par)
{
	vector <int> id;
	for (auto& pipe : pipe_group) {
		if (f(pipe.second, par))
			id.push_back(pipe.second.getIdPipe());
	}
	return id;
}

template <typename T>
vector <int> findCSByParametr(unordered_map <int, CS>& cs_group, filter_cs<T> f, T par)
{
	vector <int> id;
	for (auto& CS : cs_group) 
	{
		if (f(CS.second, par))
			id.push_back(CS.second.getIdCs());
	}
	return id;
}

