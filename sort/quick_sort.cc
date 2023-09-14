#include "quick_sort.h"

int partition(vector<int> &arr, int begin, int end)
{

    int pivot = arr[end];
    int i = begin, j = end;
    while (i != j)
    {
        while (arr[i] < pivot && i != j)
        {
            i++;
        }
        arr[j] = arr[i];
        while (arr[j] >= pivot && j != i)
        {
            j--;
        }
        arr[i] = arr[j];
    }
    arr[i] = pivot;
    return i;
}

void quick_sort(vector<int> &arr, int i, int j)
{
    if (i >= j)
    {
        return;
    }
    int q = partition(arr, i, j);
    quick_sort(arr, i, q - 1);
    quick_sort(arr, q + 1, j);
}