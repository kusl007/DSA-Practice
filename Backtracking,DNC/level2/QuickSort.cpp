// place a single number to its position and other part recursion will handle
// solved using partition logic

#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{

    // choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // find right position for pivot element and place it there
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivotElement)
        {
            count++;
        }
    }
    // yaha aauda samma the pivot position is ready
    int rightIndexOfPivot = s + count;
    swap(arr[pivotIndex], arr[rightIndexOfPivot]);
    pivotIndex = rightIndexOfPivot;

    // left ma sabai sano ani right ma sabai thulo banaune
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // there may be 2 case
        //  found the elements to swap
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }

        // didnt find th elements to swap
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // 1 case handle
    // partition logic, it returns pivot element
    int p = partition(arr, s, e);

    // recursive calls
    // left of pivot element
    quickSort(arr, s, p - 1);

    // right of pivot element
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 1, 3, 4, 20, 50, 30};
    int n = 7;
    int s = 0;
    int e = n - 1;
    quickSort(arr, s, e);
    for (auto i : arr)
    {
        cout << i << ' ';
    }

    return 0;
}