
#include <iostream>
#include <vector>
using namespace std;

void SubSequenceFinder(string &str, string output, vector<string> &arr, int i)
{
    if (i >= str.length())
    {
        // store
        arr.push_back(output);

        return;
    }

    // exclude
    SubSequenceFinder(str, output, arr, i + 1);

    // include
    output.push_back(str[i]);
    SubSequenceFinder(str, output, arr, i + 1);
}

int main()
{
    string str = "abc";
    string output = "";
    vector<string> arr;
    int i = 0;
    SubSequenceFinder(str, output, arr, i);
    cout << "printing all the sub sequences" << endl;
    for (auto i : arr)
    {
        cout << i << "  ";
    }

    return 0;
}