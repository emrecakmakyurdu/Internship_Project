// This class includes counting sort algorithm which takes array to be sorted and array size as an input.

#pragma once
#include <math.h>
#ifndef CountingSort_h
#define CountingSort_h
#include <iostream>

using namespace std;

template< typename T >
class CountingSort {
public:

	CountingSort(T* Array, int n)
	{
		int i = 0;

		i_count = 0;
		Array_size = n;

		a = new T[Array_size];
		sorted = new T[Array_size];

		for (i = 0; i < Array_size; i++)	//Transfer all elements to private class member a.
		{
			a[i] = Array[i];
		}

		CreateCountArray();
	}
	
	T findMaxIndex()	// Finds the maximum element in the array.
	{
		int i = 0;

		T max = 0;
		max = a[0];

		for (i = 1; i < Array_size - 2; i++)
		{
			i_count++;
			if (isgreater(a[i + 1], max))
			{
				max = a[i + 1];
			}
		}

		return max;
	}
	void CreateCountArray()		// Creates count array which is an important feature of this algorithm. It allocates space using the maximum element. Increment by 1 at the index of the array to be sorted.
								// Shift the array to right by 1 index and set the first element to 0.
	{
		int size = findMaxIndex();
		int i = 0;
		count = new T[size +1];

		for (i = 0; i < size+1; i++)
		{
			i_count++;
			count[i] = 0;
		}
		for (i = 0; i < Array_size; i++)	// Increment the element by 1 at the index of the array to be sorted. 
		{
			i_count++;
			count[int(a[i])]++;
		}
		for (i = 1; i < size+1; i++)
		{
			i_count++;
			count[i] = count[i] + count[i - 1];	// Cumulative sum.
		}
		for (i = size ; i >= 0; i--)	// Shift to right by 1 index.
		{
			i_count++;
			count[i + 1] = count[i];
		}
		count[0] = 0;	// Set first element to 0.
	}

	T* Sort()
	{
		int i = 0;
		for (i = 0; i < Array_size; i++)	// Locate the index of the element by using count[a[i]] and set first element to sorted array. 
		{
			i_count++;
			sorted[int(count[int(a[i])])] = a[i];
			count[int(a[i])]++;
		}
		return sorted;
	}

	int getIterationCount()			// Obtain total iteration count.
	{
		return i_count;
	}

	void Display()		// Display the contents.
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
			cout << sorted[i] << " ";
		}
		cout << endl << endl;
	}
	
	~CountingSort()		// Clear up the heap.
	{
		delete[] a;
		delete[] sorted;
	}

private:
	T* sorted;
	T* a;
	T* count;
	int Array_size, i_count;
};

#endif