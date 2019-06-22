#include "Sorter.h"
#include "bits/stdc++.h"
typedef double dl;
#ifndef TESTBED_H
#define TESTBED_H
using namespace std;
class Testbed
{
public:
    int* arr;
    void GenerateRandomList(int,int,int);
    void GenerateReverseOrderedList(int,int,int);
    dl   RunOnce(Sorter<int>*,int*,int) ;
    dl   RunAndAverage(Sorter<int>*, bool, int, int, int, int);
    void RunExperiment(Sorter<int>*, bool, int, int, int, int, int, int);
};



#endif // TESTBED_H
