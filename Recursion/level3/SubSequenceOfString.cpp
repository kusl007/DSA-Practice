// sub sequence of string
// it requires inclusion and exclusion
// vvi in recursion
// the ans will be 2^n

#include <iostream>
using namespace std;

void SubSequenceFinder(string str, string output, int i)
{
    if (i >= str.length())
    {
        cout << "the output are => " << output << endl;
        return;
    }

    // exclude
    SubSequenceFinder(str, output, i + 1);

    // include
    output.push_back(str[i]);
    SubSequenceFinder(str, output, i + 1);

    // if wanna write exclude in bottom must remove the included part in top
    // exclude
    //   output.pop_back();
    // SubSequenceFinder(str,output,i+1);
}

int main()
{
    string str = "abc";
    string output = "";
    int i = 0;
    SubSequenceFinder(str, output, i);

    return 0;
}