#include <iostream>
#include "insertionSort.h"
#include "Testbed.h"
using namespace std;
class NormalInsertion:public insertionSort
{
public :
    void insertionSortt(int *arr, int n)
    {
        for (int i = 1 ; i < n ; i++)
        {
            int temp = arr[i],j ;
            for (j=i; j>0&&temp<arr[j-1]; j--)
            {
                arr[j]=arr[j-1];
            }
            arr[j]=temp;
        }

    }
};

class BinaryInsertion:public insertionSort
{
public :
int BinarySearch(int *arr,int value, int low,int high)
    {
        int mid = (low+high)/2 ;
        if(low<high)
        {

            if (value == arr[mid]) return mid+1 ;
            if (value > arr[mid]) return BinarySearch( arr,value, mid+1,high);
            return BinarySearch(arr,value,low,mid-1);

        }
        if (value > arr[mid]) return low +1;
        return low ;
    }
void insertionSortt (int *arr,int n)
    {

        for (int i = 1 ; i < n ; i++)
        {
            int temp = arr[i],j ;
            j = i- 1 ;
            int loc = BinarySearch(arr,temp,0,j);
            while(j>=loc)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
        }
    }
};

int main()
{
    insertionSort *sort1 = new BinaryInsertion;
    insertionSort *sort2 = new NormalInsertion;
    Testbed Test;
    cout<<"Insertion sort one "<<endl;
    Test.RunExperiment(sort1, 0, 1, 1000000, 0, 10000, 100, 500);
    cout<<"Insertion sort two "<<endl;
    Test.RunExperiment(sort2, 10, 1, 1000000, 0, 10000, 100, 500);

    return 0;
}
