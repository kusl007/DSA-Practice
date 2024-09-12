
#include <iostream>
using namespace std;

int WaysToReachNthStair(int n)
{
    if (n == 0 || n == 1)
    {

        return 1;
    }

    int ans = WaysToReachNthStair(n - 1) + WaysToReachNthStair(n - 2);
    return ans;
}

int main()
{
    int n;
    cout << "enter the number of stairs" << endl;
    cin >> n;
    cout << "The ways to reach the nth stair is" << endl;
    int ans = WaysToReachNthStair(n);
    cout << ans;
    ;

    return 0;
}