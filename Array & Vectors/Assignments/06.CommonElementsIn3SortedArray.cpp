#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> findCommonElements(int a[], int b[], int c[], int size1, int size2, int size3) {
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2 && k < size3) {
        // If all three arrays have the same element
        if (a[i] == b[j] && b[j] == c[k]) {
            ans.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        // If a[i] is smaller, increment i
        else if (a[i] < b[j]) {
            i++;
        }
        // If b[j] is smaller, increment j
        else if (b[j] < c[k]) {
            j++;
        }
        // Otherwise, increment k
        else {
            k++;
        }
    }
    return ans;  // Return the common elements
}

int main() {
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int size1 = 6;
    int arr2[] = {6, 7, 20, 80, 100};
    int size2 = 5;
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int size3 = 8;

    vector<int> ans = findCommonElements(arr1, arr2, arr3, size1, size2, size3);
    
    // Using a set to ensure unique elements
    set<int> st;
    for (auto i : ans) {
        st.insert(i);  // Insert common elements into the set
    }

    // Printing unique common elements
    for (auto i : st) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
