// leetcode 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/



class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m == 0) return 0;  // If needle is empty, return 0 as per convention
        
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (needle[j] != haystack[i + j]) break;
            }
            if (j == m) {
                return i;  // Found the needle in haystack at index i
            }
        }
        return -1;  // Needle not found
    }
};
