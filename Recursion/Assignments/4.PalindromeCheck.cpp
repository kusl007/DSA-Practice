#include <iostream>
using namespace std;

bool PalindromeCheck(string &str, int i, int j) {
    if (i >= j) {
        return true;
    }
    
    if (str[i] == str[j]) {
        i++;
        j--;
     
        return PalindromeCheck(str, i, j);
    }
    
    return false;
}

int main() {
    string str = "rr";
    int i = 0;
    int j = str.length() - 1;

    bool ans = PalindromeCheck(str, i, j);
    if (ans) {
        cout << "The given input is a palindrome" << endl;
    } else {
        cout << "The given input is not a palindrome" << endl;
    }

    return 0;
}
