
#include <iostream>
using namespace std;

int PrintFibonacci(int n)
{
    if (n == 0 || n == 1)
    {

        return n;
    }

    int ans = PrintFibonacci(n - 1) + PrintFibonacci(n - 2);
    return ans;
}

int main()
{
    int n;
    cout << "enter the number" << endl;
    cin >> n;
    cout << "The Fibonacci series is" << endl;
    int ans = PrintFibonacci(n);
    cout << ans;
    ;

    return 0;
}