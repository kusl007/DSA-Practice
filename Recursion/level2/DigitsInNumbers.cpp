#include <iostream>
#include <string>

using namespace std;

void PrintDigitsInNumber(int num)
{
    // base case
    int rem = num % 10;
    if (rem == 0)
    {
        return;
    }
    num = num / 10;
    PrintDigitsInNumber(num);
    cout << rem << " ";
}

int main()
{
    int number = 987;
    PrintDigitsInNumber(number);
}
