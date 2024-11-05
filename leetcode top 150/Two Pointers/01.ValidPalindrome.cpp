//125. Valid Palindrome
//https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                ans.push_back(tolower(s[i]));
            }
        }
        int i=0,j=ans.size()-1;
        while(i<j){
            if( ans[i]!=ans[j]) {
                return false;
            }
            j--;
            i++;
        }
        return true;
        
    }
};