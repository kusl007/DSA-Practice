
#include <iostream>
#include <climits>

using namespace std;

void FindMaxElement(int arr[], int size, int i, int &maxi)
{
    // base case
    if (i >= size)
    {
        return;
    }

    // solve 1 case
    //   if (arr[i]>maxi){
    //       maxi=arr[i];
    //   }
    maxi = max(maxi, arr[i]);

    return FindMaxElement(arr, size, i + 1, maxi);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 110, 5};
    int size = 7;
    int index = 0;
    int maxi = INT_MIN;

    FindMaxElement(arr, size, index, maxi);
    cout << "The max element in the array is " << maxi << endl;

    return 0;
}