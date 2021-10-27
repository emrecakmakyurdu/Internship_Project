// This class includes quick sort algorithm (middle element as pivot) which takes array to be sorted and array size as an input.

#pragma once
#ifndef QuickSortMiddle_h
#define QuickSortMiddle_h
#include <iostream>

using namespace std;

template <typename T>
class QuickSortMiddle
{

public:

	QuickSortMiddle(T* a, int size)
	{
		int i = 0;

		Array_size = size;
		count = 0;

		arr = new T[Array_size];

		for (i = 0; i < Array_size; i++)	//Transfer all elements to private class member a.
		{
			arr[i] = a[i];
		}
	}

	void swap(T* a, T* b)	// Swap two elements. 
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	void Sort(T* a, int lo_idx, int hi_idx)		// Two indexes are initialized. One of them used for scanning up (i) and the other one is used for scanning down (j). Middle element is selected as pivot.
												// Left side of the array is scanned until larger element is found and index of that item is saved (i). Similarly, right side of the array is scanned until smaller element is found.
												// and index of that element is saved (j). If i<=j swap these two elements and recursively call sort. 
	{
		int i = lo_idx, j = hi_idx;
		T pivot = a[lo_idx + (hi_idx - lo_idx) / 2];

		if (isgreaterequal(lo_idx, hi_idx))
		{
			return;
		}

		while (isgreaterequal(j, i))
		{
			while (isgreater(pivot, arr[i]))	// Element is smaller than pivot
			{
				i++;	//increment Scan Up
				count++;
			}
			while (isgreater(arr[j], pivot))	// Element is larger than pivot
			{
				j--;	//decrement scan down. 
				count++;
			}
			if (isgreaterequal(j, i))
			{
				swap(&arr[i], &arr[j]);	//Swap
				i++;
				j--;
			}
		}
		if (isgreater(j, lo_idx))
		{
			Sort(arr, lo_idx, j);	// Recursively call sort.
		}
		if (isgreater(hi_idx, i))
		{
			Sort(arr, i, hi_idx); // Recursively call sort.
		}
	}

	int getIterationCount()		// Obtain total iteration count.
	{
		return count;
	}

	void Display(T* a)	// Display the contents.
	{
		int i = 0;
		cout << "Array before sorting :" << endl;
		for (i = 0; i < Array_size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cout << "Array after sorting :" << endl;
		for (i = 0; i < Array_size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << endl;
	}

	~QuickSortMiddle()	// Clear up the heap.
	{
		delete[] arr;
	}
private:
	T* arr;
	int Array_size, count;


};

#endif