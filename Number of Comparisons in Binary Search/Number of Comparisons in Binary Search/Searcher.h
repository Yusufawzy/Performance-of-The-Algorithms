#pragma once
#include "Searcher.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <random>
using namespace std;
class Searcher
{
private:
	int comp_count;
public:
	void LoadData(int num, vector<string>& myvector, ifstream & file);
	int binarySearch(int l, int r, string target, vector<string>& myvector);
	int testPerformance(int maxSize, double & stime1, int & scount1, double & stime2, int & scount2);
	Searcher();
	~Searcher();
};

