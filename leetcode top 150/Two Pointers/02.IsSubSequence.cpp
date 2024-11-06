// 392. Is Subsequence
//https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            while (j < t.size() && s[i] != t[j]) {
                j++;
            }
            if (j == t.size()) {
                return false;
            }
            j++;
        }
        return true;
    }
};


