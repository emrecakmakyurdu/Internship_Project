#ifndef QuickSortFirst_h
#define QuickSortFirst_h
#include <iostream>

using namespace std;

template<typename T>
class QuickSortFirst
{
public:

	QuickSortFirst(T* a, int size)
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

	int partition(T* a, int lo_idx, int hi_idx)	// Select first element as pivot and make partition. After first iteration array is divided into two parts.
												// The pivot is moved to the last compared element of the array (i-1) and last compared element is moved to the first place.  
												// Items smaller than the pivot is at left of the array and items larger than pivot is at the right of the array. Last comparision index (i-1)
												// is returned as partition.
	{
		int i = lo_idx + 1, j;
		T pivot = arr[lo_idx];

		for (j = lo_idx + 1; j <= hi_idx; j++)	// Iterate from second item to last item.
		{
			count++;
			if (isgreater(arr[lo_idx], arr[j]))	// Obtain smaller elements than pivot and swap starting from first index (i = lo_idx+ 1). Increment i.
			{
				swap(&arr[j], &arr[i]);
				i++;
			}
		}
		swap(&arr[i - 1], &arr[lo_idx]);

		return i - 1;	// Return last comparision index.
	}

	void Sort(T* arr, int lo_idx, int hi_idx)	// Recursively call Sort.
	{
		if (lo_idx < hi_idx)
		{
			int p = partition(arr, lo_idx, hi_idx);	// Obtain partition index.
			Sort(arr, lo_idx, p - 1);	// Sort left side of the array.
			Sort(arr, p + 1, hi_idx);	// Sort right side of the array.
		}
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

	int getIterationCount()	// Obtain total iteration count.
	{
		return count;
	}

	~QuickSortFirst()	// Clear up the heap.
	{
		delete[] arr;
	}

private:
	int Array_size, count;
	T* arr;
};

#endif
