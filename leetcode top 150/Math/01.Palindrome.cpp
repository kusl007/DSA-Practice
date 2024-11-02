//9. Palindrome Number
//https://leetcode.com/problems/palindrome-number/submissions/1440773490/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isPalindrome(int x) {

         if (x < 0) {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};