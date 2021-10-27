// This class instantiates all sorting algorithms and displays the contents while calculating measured time
// and total iteration count according to the algorithm which is taken as an input. 

#pragma once
#ifndef SortAll_h
#define SortAll_h

#include "CountingSort.h"	
#include"RadixSort.h"
#include "QuickSortLast.h"
#include "QuickSortFirst.h"
#include "QuickSortMiddle.h"
#include "BubbleSort.h"
#include "SortAll.h"
#include <chrono>

using namespace std;

template<typename T>
class SortAll
{
public:
	SortAll(T* a, int n, int algo)
	{
		Array = a;
		size = n;
		algorithm = algo;
	}
	void Sort()
	{
		int i = 0, c = 0;

		if (algorithm == 1)
		{
			CountingSort<T> A(Array, size);
			auto start5 = chrono::high_resolution_clock::now();
			ios_base::sync_with_stdio(false);
			A.Sort();
			auto end5 = chrono::high_resolution_clock::now();
			double CountingSortTime = chrono::duration_cast<chrono::nanoseconds>(end5 - start5).count();
			CountingSortTime *= 1e-9;
			cout << "--------------------Counting Sort :--------------------" << endl;
			//A.Display();
			cout << "Total Duration : " << CountingSortTime << " seconds" << endl;
			cout << "Total Iteration Count : " << A.getIterationCount() << endl;
		}

		else if (algorithm == 2)
		{
			QuickSortFirst <T> B(Array, size);
			auto start6 = chrono::high_resolution_clock::now();
			ios_base::sync_with_stdio(false);
			B.Sort(Array, 0, size - 1);
			auto end6 = chrono::high_resolution_clock::now();
			double QuickSortFirstTime = chrono::duration_cast<chrono::nanoseconds>(end6 - start6).count();
			cout << "-------------------- Quick Sort (First Element as Pivot) --------------------" << endl;
			QuickSortFirstTime *= 1e-9;
			//B.Display(Array);
			cout << "Total Duration : " << QuickSortFirstTime << " seconds" << endl;
			cout << "Total Iteration Count : " << B.getIterationCount() << endl;
		}

		else if (algorithm == 3)
		{
			QuickSortLast <T> C(Array, size);
			auto start7 = chrono::high_resolution_clock::now();
			ios_base::sync_with_stdio(false);
			C.Sort(Array, 0, size - 1);
			auto end7 = chrono::high_resolution_clock::now();
			double QuickSortLastTime = chrono::duration_cast<chrono::nanoseconds>(end7 - start7).count();
			QuickSortLastTime *= 1e-9;
			cout << "-------------------- Quick Sort (Last Element as Pivot) :--------------------" << endl;
			//C.Display(Array);
			cout << "Total Duration : " << QuickSortLastTime << " seconds" << endl;
			cout << "Total Iteration Count : " << C.getIterationCount() << endl;
		}

		else if (algorithm == 4)
		{
			QuickSortMiddle <T> D(Array, size);
			auto start8 = chrono::high_resolution_clock::now();
			ios_base::sync_with_stdio(false);
			D.Sort(Array, 0, size - 1);
			auto end8 = chrono::high_resolution_clock::now();
			double QuickSortMiddleTime = chrono::duration_cast<chrono::nanoseconds>(end8 - start8).count();
			QuickSortMiddleTime *= 1e-9;
			cout << "-------------------- Quick Sort (Middle Element as Pivot) :--------------------" << endl;
			//D.Display(Array);
			cout << "Total Duration : " << QuickSortMiddleTime << " seconds" << endl;
			cout << "Total Iteration Count : " << D.getIterationCount() << endl;
		}

		else if (algorithm == 5)
		{
			RadixSort <T> E(Array, 1, size);
			auto start9 = chrono::high_resolution_clock::now();
			ios_base::sync_with_stdio(false);
			c = E.findDigitCount();
			for (i = 0; i < c; i++)
			{
				Array = E.sort(Array, size, pow(10, i));
			}
			auto end9 = chrono::high_resolution_clock::now();
			double RadixSortTime = chrono::duration_cast<chrono::nanoseconds>(end9 - start9).count();
			RadixSortTime *= 1e-9;
			cout << "--------------------Radix Sort :--------------------" << endl;
			E.Display();
			cout << "Total Duration : " << RadixSortTime << " seconds" << endl;
			cout << "Total Iteration Count : " << E.getIterationCount() << endl;
		}

		else if (algorithm == 6)
		{
			BubbleSort <T> F(Array, size);
			auto start10 = chrono::high_resolution_clock::now();
			ios_base::sync_with_stdio(false);
			F.Sort();
			auto end10 = chrono::high_resolution_clock::now();
			double BubbleSortTime = chrono::duration_cast<chrono::nanoseconds>(end10 - start10).count();
			BubbleSortTime *= 1e-9;
			cout << "-------------------- BubbleSort :--------------------" << endl;
			//F.Display(Array);
			cout << "Total Duration : " << BubbleSortTime << " seconds" << endl;
			cout << "Total Iteration Count : " << F.getIterationCount() << endl;
		}
	}

private:
	T* Array;
	int size, algorithm;
};

#endif // !