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
	int x;
	while ((cin >> x).fail() || (x < min) || (x > max)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Type number (" << min << "-" << max << "):";
	}
	return x;
}
template <typename T> 
using filter_pipe = bool (*) (pipe& p, T par);

template <typename T>
using filter_cs = bool (*) (cs& cs, T par);

template <typename T>
vector <int> parametr_p(unordered_map <int, pipe>& pipe_group, filter_pipe<T> f, T par)
{
	vector <int> id;
	for (auto& pipe : pipe_group) {
		if (f(pipe.second, par))
			id.push_back(pipe.second.getIdP);
	}
	return id;
}

template <typename T>
vector <int> parametr_cs(unordered_map <int, cs>& cs_group, filter_cs<T> f, T par)
{
	vector <int> id;
	for (auto& cs : cs_group) 
	{
		if (f(cs.second, par))
			id.push_back(cs.second.getIdP);
	}
	return id;
}