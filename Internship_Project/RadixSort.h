// This class includes radix sort algorithm which takes array to be sorted, base (determines which digit to apply radix sort) and array size as an input.

#pragma once
#ifndef RadixSort_h
#define RadixSort_h
#include <iostream>

using namespace std;

template <typename T>
class RadixSort
{
public:

	RadixSort(T* Array, int base, int n)
	{
		int i = 0, j = 0;

		Array_size = n;
		maxDigitCount = 10;
		i_count = 0;
		base_digit = base;

		a = new T[Array_size];
		sorted = new T[Array_size];
		digit = new T[Array_size];

		for (i = 0; i < Array_size; i++)
		{
			a[i] = Array[i];	//Transfer all elements to private class member a.
		}
	}

	T findMax()		// Find maximum element. 
	{
		int i = 1;
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

	int findDigitCount()	// Find total digit count. (i.e. 1234 is 4 digit number)
	{
		int i = 0;
		int max = findMax();
		for (int i = maxDigitCount - 1; i >= 0; i--)
		{
			i_count++;
			if (floor(max / pow(10, i)) != 0)
			{
				return i + 1;
			}
		}
	}

	void CountingSortModified(T* Array, int n, int base)	// This function is very similar to counting sort algorithm. The only difference is, in radix sort counting sort is applied 
															// to digits and arrange the array. 
	{
		int size = findMax();
		count = new T[size + 1];
		int i = 0;

		for (i = 0; i < size + 1; i++) // SÝZE OLABÝLÝR ??
		{
			count[i] = 0;
		}
		for (i = 0; i < Array_size; i++)
		{
			i_count++;
			++count[(int(a[i]) / base) % 10];
		}
		for (i = 1; i < size; i++)
		{
			i_count++;
			count[i] = count[i] + count[i - 1];
		}
		for (i = size - 1; i >= 0; i--)
		{
			i_count++;
			count[i + 1] = count[i];
		}
		count[0] = 0;
	}

	T* sort(T* Array, int n, int base)	// Sort the array.
	{
		int i = 0;
		if (base == 1)
		{
			CountingSortModified(Array, n, base);
			for (i = 0; i < Array_size; i++)
			{
				i_count++;
				sorted[int(count[(int(a[i]) / base) % 10])] = a[i];
				digit[int(count[(int(a[i]) / base) % 10])] = a[i];
				count[(int(a[i]) / base) % 10]++;
			}
		}
		else
		{
			CountingSortModified(Array, n, base);
			for (i = 0; i < Array_size; i++)
			{
				i_count++;
				digit[i] = Array[i];
			}
			for (i = 0; i < Array_size; i++)
			{
				i_count++;
				sorted[int(count[(int(digit[i]) / base) % 10])] = digit[i];
				count[(int(digit[i]) / base) % 10]++;

			}
		}
		return sorted;
	}

	int getIterationCount()	// Obtain total iteration count.
	{
		return i_count;
	}

	void Display()	// Display the contents.
	{
		int i = 0, j = 0;
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

	~RadixSort()	// Clear up the heap.
	{
		delete[] a;
		delete[] digit;
		delete[] count;
	}

private:
	T* a, * sorted, * digit, * count;
	int base_digit, Array_size, maxDigitCount, i_count;
};

#endif