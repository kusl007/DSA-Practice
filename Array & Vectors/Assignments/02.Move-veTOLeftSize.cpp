#include <iostream>
using namespace std;

void moveAllNegativeToLeft(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        if (arr[left] < 0) {
            left++;  // Move the left pointer if it's already negative
        } else if (arr[right] > 0) {
            right--;  // Move the right pointer if it's already positive
        } else {
            // Swap negative element from right to left
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int a[] = {1, 2, -3, 4, -5, 6};
    int size = 6;
    moveAllNegativeToLeft(a, size);

    // Print the modified array
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
