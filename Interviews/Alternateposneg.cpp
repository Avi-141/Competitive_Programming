#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Partitioning routine of quicksort
int partition(int A[], int n)
{
	int j = 0;
	int pivot = 0;	// consider 0 as pivot

	// each time we find a negative number, j is incremented
	// and negative element would be placed before the pivot
	for (int i = 0; i < n; i++)
	{
		if (A[i] < pivot)
		{
			swap(A[i], A[j]);
			j++;
		}
	}

	// j holds index of first positive element
	return j;
}

// Function to rearrange given array such that it contains positive
// and negative numbers at alternate positions
int rearrange(int A[], int size)
{
	// partition given array such that all positive elements move
	// to end of the array
	int p = partition(A, size);

	// swap alternate negative element from next available positive
	// element till end of array is reached or all negative or
	// positive elements are exhausted.
	for (int n = 0; (p < size && n < p); p++, n += 2) {
		swap(A[n], A[p]);
	}
}

int main()
{
	int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
	int n = sizeof(A)/sizeof(A[0]);

	rearrange(A, n);

	// print the rearranged array
	for (int i = 0 ; i < n; i++) {
		cout << setw(3) << A[i];
	}

	return 0;
}