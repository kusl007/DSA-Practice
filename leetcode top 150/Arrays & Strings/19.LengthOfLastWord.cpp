// 58. Length of Last Word
//https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150 


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int length = 0;
        int i = n - 1;

        
        while ( s[i] == ' ') {
            i--;
        }

        // Count the last word
        for (; i >= 0; i--) {
            if (s[i] == ' ') {
                break; // Stop counting at the first space
            } else {
                length++;
            }
        }
        
        return length;
    }
};
