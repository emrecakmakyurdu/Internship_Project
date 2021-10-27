// This class includes the bubble sort algorithm which takes the array to be sorted and array size as an input.

#pragma once
#ifndef BubbleSort_h
#define BubbleSort_h
#include <iostream>

using namespace std;
template< typename T >
class BubbleSort
{
public:

	BubbleSort(T* a, int n)
	{
		size = n;
		arr = new T[size];
		int i = 0;

		for (i = 0; i < size; i++)	// Transfer all elements to private class member arr.
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

	void Sort()
	{
		int i = 0, j = 0;

		for (i = 0; i < size; i++)	// Iterate over the entire array.
		{
			count++;
			for (j = 0; j < size - i - 1; j++)	// Iterate through size - i -1. At each iteration at least one element is in correct position.
			{
				count++;
				if (isgreater(arr[j], arr[j + 1]))	// If next element is greater, swap next element with the current.
				{
					swap(&arr[j], &arr[j + 1]);
				}
			}
		}
	}

	void Display(T* a)	//Display the contents.
	{
		int i = 0;

		cout << "Array before sorting :" << endl;
		for (i = 0; i < size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cout << "Array after sorting :" << endl;
		for (i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << endl;
	}

	int getIterationCount()	// Obtain total iteration count.
	{
		return count;
	}

	~BubbleSort()	// Clear up the heap.
	{
		delete[] arr;
	}

private:
	int count, size;
	T* arr;

};

#endif // !BubbleSort_h
