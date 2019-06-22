#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include "Sorter.h"
#include "bits/stdc++.h"
using namespace std;
template <class T>
class QuickSorter :	public Sorter<T>
{
	void Sort(T*, int , int );
public:
	void Sort(T*, int);

};
template<class T>
void QuickSorter<T>::Sort(T* arr, int left, int right) {
    if(left >=right) return;
	int L = left, R = right; // swap(arr[left], arr[(left + right) / 2]);
	int pivot = arr[(left + right) / 2];
	while (L <= R) {
		while (arr[L] < pivot) L++;
		while (arr[R] > pivot) R--;
		if (L <= R) {
        swap(arr[L],arr[R]);
        L++; R--;
		}
	}
	if (left < R ) Sort(arr, left, R - 1);
	if (left<right) Sort(arr, L, right);

}
template<class T>
void QuickSorter<T>::Sort(T* arr, int len) {
	Sort(arr, 0, len - 1);
}


#endif // QUICKSORTER_H
