#include <bits/stdc++.h>
#include "testbed.h"
#include "insertionSort.h"
using namespace std;

class insertionSort_one:public insertionSort
{
public :
    void insertionSortt(int arr[], int n)
    {
        for (int i = 1,j; i < n; i++)
        {
            int tmp = arr[i];
            for (j = i; j > 0 && tmp < arr[j-1] ; j--)
                arr[j] = arr[j-1];
            arr[j] = tmp;
        }
    }
};
class insertionSort_two:public insertionSort{
public :
void insertionSortt(int arr[],int size)
{
    for(int i=2;i<size;i+=2)
    {
        int MAX=max(arr[i],arr[i-1]);
        int MIN=min(arr[i],arr[i-1]);
        int j=i;
        for( ;(j>1 && MAX<arr[j-2]) ;j--)
            arr[j]=arr[j-2];
        arr[j]=MAX;
        for( j-=1;j>0 && MIN<arr[j-1] ;j--)
            arr[j]=arr[j-1];
        arr[j]=MIN;
    }
    if(size%2==0)
    {
        int MIN=arr[size-1];
        int j=size-1;
        for(;j>0 && MIN<arr[j-1] ;j--)
            arr[j]=arr[j-1];
        arr[j]=MIN;
    }
}
};

int main()
{
    srand(time(0));
    insertionSort *sort1 = new insertionSort_one ;
    insertionSort *sort2 = new insertionSort_two ;
    fstream data1;data1.open("data1.txt",ios::trunc|ios::out);
    fstream data2;data2.open("data2.txt",ios::trunc|ios::out);
 	Testbed Test;

 	cout<<"Insertion sort one "<<endl;
    Test.RunExperiment(sort1, 0, 1, 1000000, 0, 10000, 100, 500);
    cout<<"Insertion sort two "<<endl;
    Test.RunExperiment(sort2, 10, 1, 1000000, 0, 10000, 100, 500);
    data1.close();
    data2.close();
    return 0;
}
