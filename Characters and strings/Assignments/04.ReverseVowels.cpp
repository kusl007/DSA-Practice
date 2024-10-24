//leetcode 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);  // Make it case-insensitive
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            // Check if both s[i] and s[j] are vowels
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            // Move `i` forward if s[i] is not a vowel
            else if (!isVowel(s[i])) {
                i++;
            }
            // Move `j` backward if s[j] is not a vowel
            else {
                j--;
            }
        }
        return s;
    }
};
