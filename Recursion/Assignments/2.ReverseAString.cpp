
#include <iostream>
using namespace std;

void ReverseString(string &str, int n, int i)
{
    if (i >= n)
    {
        return;
    }

    swap(str[i], str[n]);

    ReverseString(str, n - 1, i + 1);
    return;
}
int main()
{

    string str = "abcdefg";
    int length = str.length();
    int i = 0;

    ReverseString(str, length - 1, i);

    cout << "The reversed string is " << str << endl;

    return 0;
}