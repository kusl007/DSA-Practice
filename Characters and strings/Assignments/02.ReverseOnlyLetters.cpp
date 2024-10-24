//leetcode 917. Reverse Only Letters
// https://leetcode.com/problems/reverse-only-letters/description/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            if (!isalpha(s[i])) {  // Check if the character is not a letter
                i++;
            }
            else if (!isalpha(s[j])) {  // Check if the character is not a letter
                j--;
            }
            else {
                swap(s[i], s[j]);  // Swap the letters
                i++;
                j--;
            }
        }
        
        return s;  // Return the modified string
    }
};