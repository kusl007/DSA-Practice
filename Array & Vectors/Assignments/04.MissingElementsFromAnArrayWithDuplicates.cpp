#include <iostream>
#include <cmath>  // for abs() function
using namespace std;

int findMissingElements(int arr[], int size) {
    int ans = -1;

    // Marking elements as negative to keep track of visited numbers
    for (int i = 0; i < size; i++) {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0) {
            arr[index] *= -1;
        }
    }

    // Finding the first positive index
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            ans = i + 1; // Returning missing number (index + 1)
            break;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 3, 5, 3, 4};
    int size = 5;
    int ans = findMissingElements(arr, size);
    cout << "Missing element: " << ans << endl;
    return 0;
}
