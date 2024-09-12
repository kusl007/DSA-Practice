
#include <iostream>
using namespace std;

void PrintArray(int arr[], int size, int i)
{
    if (i >= size)
    {
        return;
    }
    cout << arr[i] << " ";
    PrintArray(arr, size, i + 1);
    return;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    int index = 0;

    cout << "The array is" << endl;
    PrintArray(arr, size, index);

    return 0;
}