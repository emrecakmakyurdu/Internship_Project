#pragma once
#ifndef ApplyAlgorithm_h
#define ApplyAlgorithm_h
#include <iostream>
#include "SortAll.h"
using namespace std;

template<typename T>
class ApplyAlgorithm
{
public:
	// This function creates random array based on the given template called in main. 
	// Also, it calls the SortAll function to perform sorting. 
	ApplyAlgorithm(int size, int type)
	{
		n = size;
		t = type;
	}

	void Start()
	{
		int i = 0, algo = 0, c = 0, b = 0;
		T* a = new T[n];

		if (t == 2)
		{
			for (i = 0; i < n; i++)			// Create random char array.
			{
				b = rand() % 26;
				a[i] = 'a' + b;
			}
		}
		else if (t == 0 || t == 1 || t == 3)
		{
			for (i = 0; i < n; i++)		// Create random int array.
			{
				a[i] = i;
				//a[i] = rand() % 500;

			}
		}

		cout << "Please select the sorting algorithm :" << endl;
		cout << "0. To exit " << endl;
		cout << "1. Counting Sort \n2. Quick Sort (First Element as Pivot) " << endl;
		cout << "3. Quick Sort (Last Element as Pivot) \n4. Quick Sort (Middle Element as Pivot)" << endl;
		cout << "5. Radix Sort \n6. Bubble Sort" << endl << endl;
		cout << "Maximum possible array size : " << n << endl;

		while (true)
		{
			cout << endl;
			cout << "Enter the number of the algorithm to be used : " << endl;
			cin >> algo;

			if (algo == 0)
			{
				return;
			}
			if (algo < 0 || algo > 6)
			{
				cout << "Algorithm is not defined. Enter the number of the algorithm to be used : " << endl;
				cin >> algo;
				if (algo == 0)
				{
					return;
				}
			}

			cout << "Enter the number of elements : ";
			cin >> c;

			if (isgreater(c, n))
			{
				cout << "Size should not exceed the maximum array size. " << endl << "Enter the number of elements : ";
				cin >> c;
			}

			SortAll<T> A(a, c, algo);
			A.Sort();
		}
	}

	//~ApplyAlgorithm();
private:
	int n, t;
};

#endif
