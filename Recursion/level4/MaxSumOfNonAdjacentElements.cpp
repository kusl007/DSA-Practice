// we have  to return the maximum no  of sunsequence in which no two elements are adjacent

// example :2,1,4,9
// here the sum are 2+4=6,2+9=11,1+9=10
// and the maximum of these are 11
// so our answer is 11;
// inclusion and  exclusion pattern

// include i=i+2;
// exclude i=i+1;

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int sum, int &maxi, int i)
{
    // base case
    if (i >= arr.size())
    {
        maxi = max(sum, maxi);
        return;
    }
    // include
    solve(arr, sum + arr[i], maxi, i + 2);
    // exclude
    solve(arr, sum, maxi, i + 1);
}

int main()
{

    vector<int> arr{1, 2, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, sum, maxi, i);
    cout << maxi << endl;

    return 0;
}