// first divide the array into 2 parts
// then recursion will sort the array
// then merge two sorted arrays




#include <iostream>
using namespace std;

// Function to merge two sorted halves of the array
void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays for left and right halves
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy values into left and right arrays
    int k = s;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }

    // Merge the two sorted arrays
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex] = left[leftIndex];
            leftIndex++;
        } else {
            arr[mainArrayIndex] = right[rightIndex];
            rightIndex++;
        }
        mainArrayIndex++;
    }

    // Copy any remaining elements of left array
    while (leftIndex < len1) {
        arr[mainArrayIndex] = left[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }

    // Copy any remaining elements of right array
    while (rightIndex < len2) {
        arr[mainArrayIndex] = right[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    // Free the dynamically allocated memory
    delete[] left;
    delete[] right;
}

// Recursive merge sort function
void mergeSort(int *arr, int s, int e) {
    // Base case: if the array has only one element, return
    if (s >= e) {
        return;
    }

    int mid = s + (e - s) / 2;

    // Sort the left part
    mergeSort(arr, s, mid);

    // Sort the right part
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, e);
}

int main() {
    int arr[] = {4, 5, 1, 2, 12};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
