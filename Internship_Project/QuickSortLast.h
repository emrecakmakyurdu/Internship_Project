// This class includes quick sort algorithm (last element as pivot) which takes array to be sorted and array size as an input.

#pragma once
#ifndef QuickSortLast_h
#define QuickSortLast_h
#include <iostream>

using namespace std;

template <typename T>
class QuickSortLast
{
public:

	QuickSortLast(T* a, int size)
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

	int partition(T* a, int lo_idx, int hi_idx)	// Select last element as pivot and make partition. 
	{
		T pivot = arr[hi_idx];
		int i = lo_idx - 1;  // index of smaller element. Indicates the partition location.
		int j = 0;

		for (j = lo_idx; j < hi_idx; j++)
		{
			count++;
			if (isgreaterequal(pivot, arr[j]))	// If current element is smaller than or equal to the pivot
			{
				i++;	// Increment the smaller index.
				swap(&arr[i], &arr[j]);		// Swap current element and small index.
			}
		}
		swap(&arr[i + 1], &arr[hi_idx]);	// Swap small index with last element. Left of the small index is smaller while left of the array is larger.

		return (i + 1);	//Return the small index. 
	}

	void Sort(T* arr, int lo_idx, int hi_idx)	// Recursively call Sort.
	{
		if (isgreater(hi_idx, lo_idx))
		{
			int p = partition(arr, lo_idx, hi_idx);		// Obtain partition index.
			Sort(arr, lo_idx, p - 1);	// Sort left side of the array.
			Sort(arr, p + 1, hi_idx);	// Sort right side of the array.
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

	~QuickSortLast()	// Clear up the heap.
	{
		delete[] arr;
	}

private:
	int Array_size, count;
	T* arr;
};
#endif
