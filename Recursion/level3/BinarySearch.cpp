
#include <iostream>
#include <vector>
using namespace std;


int BinarySearch(const vector<int>& arr, int key, int start, int end) {
    // Base case: Key not found
    if (start > end) {
        return -1;
    }

    // Calculate the middle index
    int mid = start + (end - start) / 2;

    // Case 1: Key found
    if (arr[mid] == key) {
        return mid;
    }

    // Case 2: Key is less than the middle element, search the left half
    if (arr[mid] > key) {
        return BinarySearch(arr, key, start, mid - 1);
    } else {
        // Case 3: Key is greater than the middle element, search the right half
        return BinarySearch(arr, key, mid + 1, end);
    }
}

int main() {
    vector <int> arr{1,2,3,4,5,6,7};
    int key=6;
    int start=0;
    int end=arr.size()-1;

    int index = BinarySearch(arr,key,start,end);
    if(index!=-1){
        cout<<"the "<<key<<" is in index "<<index<<endl;
        
    }
    else{
        cout<<"the key is not present"<<endl;
    }
    

    return 0;
}