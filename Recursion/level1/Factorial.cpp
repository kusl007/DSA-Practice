
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int ans = n * factorial(n - 1);
    return ans;
}
int main()
{
    int n;
    cout << "enter the number" << endl;
    cin >> n;
    int ans = factorial(n);
    cout << "the factorial is " << ans;

    return 0;
}