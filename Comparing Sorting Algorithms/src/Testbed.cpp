#include "Testbed.h"
#include "SelectionSorter.h"
typedef double dl;
void Testbed::GenerateRandomList(int min, int max, int size)
{
    arr= new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % max) + min;
    }
}
void Testbed::GenerateReverseOrderedList(int min, int max, int size)
{
    delete [] arr;
    GenerateRandomList(min,max,size);
    SelectionSorter<int> s;
    s.SortReversed(arr,size);


}
dl Testbed::RunOnce(Sorter<int>* sorter, int* data, int size)
{
    clock_t c = clock();
    sorter->Sort(data, size);
    return (dl)(clock() - c);
}

dl Testbed::RunAndAverage(Sorter<int>* sorter, bool type, int min, int max, int size, int sets_num)
{
    dl TotalTime;
    for (int i = 0 ; i < sets_num ; i++)
    {
        delete []arr ;
        if (type)
        {
            arr = new int[size];
            GenerateReverseOrderedList(min,max,size);
            TotalTime+=RunOnce(sorter,arr,size);
        }
        else
        {
            arr = new int[size];
            GenerateRandomList(min,max,size);
            TotalTime+=RunOnce(sorter,arr,size);
        }
    }
    return TotalTime/sets_num ;
}

void Testbed::RunExperiment(Sorter<int>* sorter, bool type, int min, int max, int min_val, int max_val, int sets_num, int step)
{
    cout << setw(9) <<"Size" << setw(18) << "AVG Time" << endl;
    int i = min_val;
    while (i<=max_val)
    {
        cout << setw(9)  << i;
        cout<<  setw(18) << RunAndAverage(sorter, type, min, max, i, sets_num) << endl;
        i+=step;
    }
}
