// if 1,2,3 is given then the subarray is 1 , 12, 123,2,23,3

// approach starts from here
// start=0,end=start
// start=0,end=end+1;
// end upo final

// yeti ma 1 case ta aauxa but for other cases

// aba start badaune

#include <iostream>
#include <vector>
using namespace std;

void printArray_util(vector<int> &arr, int start, int end)
{

    // cout<<"start"<<start<<"end "<<end<<endl;
    // base case
    if (end >= arr.size())
    {

        return;
    }

    // single case handle
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // call recursion
    printArray_util(arr, start, end + 1);
    return;
}

// next set of subArrays

void printArray(vector<int> &arr)
{
    for (int start = 0; start < arr.size(); start++)
    {
        //  cout<<"the start is in"<<start<<arr[start]<<endl;
        int end = start;
        //  cout<<"the end is in"<<end<<arr[end]<<endl;
        printArray_util(arr, start, end);
    }

    // printArray_util(arr,0,0);
}
int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    printArray(v);

    return 0;
}
