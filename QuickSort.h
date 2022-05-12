#ifndef QUICK_SORT_h
#define QUICK_SORT_h

#include <iostream>
#include <vector>

using namespace std;

template<class T>
int partition(vector<T>& vec , int start, int end)
{
    T pivot = vec[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) 
        if (vec[i] <= pivot)
            count++;

    int pivotIndex = start + count;
    swap(vec[pivotIndex], vec[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) 
    {
        while (vec[i] <= pivot) 
            i++;
        
        while (vec[j] > pivot) 
            j--;
        
        if (i < pivotIndex && j > pivotIndex) 
            swap(vec[i++], vec[j--]);
    }

    return pivotIndex;
}

template<class T>
void quickSort(vector<T>& vec, int start, int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(vec, start, end);

    // Sorting the left part
    quickSort(vec, start, p - 1);

    // Sorting the right part
    quickSort(vec, p + 1, end);
}
#endif
