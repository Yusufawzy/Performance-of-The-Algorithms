#include "bits/stdc++.h"
#include "insertionSort.h"
typedef double dl;
#ifndef TESTBED_H
#define TESTBED_H
using namespace std;
class Testbed
{
public:
    int* arr;
    void GenerateRandomList(int,int,int);
    dl   RunOnce(insertionSort*,int*,int) ;
    dl   RunAndAverage(insertionSort*, bool, int, int, int, int);
    void RunExperiment(insertionSort*, bool, int, int, int, int, int, int);
};



#endif // TESTBED_H
