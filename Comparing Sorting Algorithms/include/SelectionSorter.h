#ifndef SELECTIONSORTER_H
#define SELECTIONSORTER_H

#include "Sorter.h"
#include <bits/stdc++.h>

template <class T>
class SelectionSorter:public Sorter<T>
{
public:
	void Sort(T* , int );
    void SortReversed(T* , int );

};

template <class T>
void SelectionSorter<T>::Sort(T*arr, int n) {
    int least ;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (int j = i + 1;j < n;j++) {
			if (arr[j] < arr[least]) least = j;

		}
		int temp = arr[least];
		arr[least]=arr[i];
		arr[i] = temp;
	}
}


template <class T>
void SelectionSorter<T>::SortReversed(T*arr, int n) {
    int least ;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (int j = i + 1;j < n;j++) {
			if (arr[j] >arr[least]) least = j;

		}
		int temp = arr[least];
		arr[least]=arr[i];
		arr[i] = temp;
	}
}
#endif // SELECTIONSORTER_H
