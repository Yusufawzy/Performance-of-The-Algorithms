#ifndef SHELLSORTER_H
#define SHELLSORTER_H
#include "Sorter.h"
template <class T>
class ShellSorter :	public Sorter<T>
{
public:

	void Sort(T*, int);

};

template <class T>
void ShellSorter<T>::Sort(T* arr, int n) {
	for (int gap = n / 2; gap > 0;gap /= 2) {
		for (int i = gap; i < n;i++) {
			int j; int temp = arr[i];
			for (j = i; j >= gap && temp < arr[j - gap];j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}


#endif // SHELLSORTER_H
