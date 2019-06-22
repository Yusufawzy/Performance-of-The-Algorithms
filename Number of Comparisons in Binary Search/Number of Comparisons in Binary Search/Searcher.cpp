#include"pch.h"
#include "Searcher.h"
#include "all.h"
using namespace std;
void Searcher::LoadData(int num, vector<string>& myvector, ifstream &file)
{
	string input;
	myvector.clear();
	for (int i = 0; i < num; i++)
	{
		file >> input;
		myvector.push_back(input);
	}
	file.seekg(0);
}
int Searcher::binarySearch(int l, int r, string target, vector<string>&myvector)
{
	if (r >= l)
	{
		comp_count++;
		int mid = l + (r - l) / 2;
		if (myvector[mid] == target)
		{
			comp_count++;
			return mid;
		}
		if (myvector[mid] > target)
		{
			comp_count++;
			return binarySearch(l, mid - 1, target, myvector);
		}
		else { comp_count++; return binarySearch(mid + 1, r, target, myvector); }
	}
	return -1;
}
int Searcher::testPerformance(int maxSize, double &stime1, int &scount1, double &stime2, int &scount2)
{
	vector<string> myvector;
	vector<string> non;
	ifstream file("words.txt");
	ifstream nfile("nonexistingwords.txt");
	LoadData(9000, non, nfile);
	LoadData(90000, myvector, file);
	clock_t START1 = clock();
	for (int i = 0; i < 100; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 90000);
		int x = dis(gen);
		binarySearch(0, maxSize, myvector[x], myvector);
		scount1 += comp_count;
	}
	clock_t END1 = clock();
	clock_t total_time1 = (END1 - START1);
	stime1 = (float)(total_time1) / 100;
	scount1 /= 100;
	clock_t START2 = clock();
	for (int i = 0; i < 100; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 9000);
		int x = dis(gen);
		binarySearch(0, maxSize, non[x], myvector);
		scount2 += comp_count;
	}
	clock_t END2 = clock();
	clock_t total_time2 = (END2 - START2);
	stime2 = (float)(total_time2) / 100;
	scount2 /= 100;
	file.close();
	nfile.close();
	return 0;
}
Searcher::Searcher()
{
}
Searcher::~Searcher()
{
}
