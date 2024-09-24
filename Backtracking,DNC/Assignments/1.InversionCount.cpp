// hacker rank problem
// https://www.hackerrank.com/challenges/ctci-merge-sort/problem



//vvi

// simple approach
// long countInversions(vector<int> arr) {
//     int count =0;
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             count=arr[i]>arr[j]?count+1:count;
//         }
//     }
//     return count;

// }


// now using merge sort

#include <iostream>
#include <vector>

using namespace std;

long mergeAndCount(vector<int> &arr, vector<int> &temp, int start, int mid, int end) {
    int i = start;     // Left subarray
    int j = mid + 1;   // Right subarray
    int k = start;     // Merged subarray
    long inv_count = 0; // To store the count of inversions

    // Merge the two subarrays
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // Inversion found, all elements left to `i` in the left subarray form an inversion with `arr[j-1]`
            inv_count += (mid - i + 1);
        }
    }

    // Copy the remaining elements of the left subarray (if any)
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray (if any)
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy the merged subarray back to the original array
    for (i = start; i <= end; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long mergeSortAndCount(vector<int> &arr, vector<int> &temp, int start, int end) {
    long inv_count = 0;
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Sort and count for the left half
        inv_count += mergeSortAndCount(arr, temp, start, mid);

        // Sort and count for the right half
        inv_count += mergeSortAndCount(arr, temp, mid + 1, end);

        // Merge both halves and count inversions
        inv_count += mergeAndCount(arr, temp, start, mid, end);
    }
    return inv_count;
}

long countInversions(vector<int> arr) {
    vector<int> temp(arr.size(), 0);
    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};
    long result = countInversions(arr);
    cout << "Number of inversions: " << result << endl;
    return 0;
}
