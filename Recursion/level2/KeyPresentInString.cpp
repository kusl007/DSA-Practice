#include <iostream>
#include <string>

using namespace std;

int FindKeyInString( string& str, char& ch, int ind) {
    // Base case: if index is out of bounds
    if (ind >= str.length()) {
        return -1;
    }

    // Check if current index has the character
    if (str[ind] == ch) {
        return ind;
    }

    // Recursive call
    return FindKeyInString(str, ch, ind + 1);
}

int main() {
    string str = "kushal bansal";
    char ch = 'k';
    int index = FindKeyInString(str, ch, 0);
    
    if (index != -1) {
        cout << "The character '" << ch << "' is at index " << index << "." << endl;
    } else {
        cout << "The character '" << ch << "' was not found in the string." << endl;
    }

    return 0;
}
