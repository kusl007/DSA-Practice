// 28.Find the Index of the First Occurrence in a String
//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        if (m==0)return 0;
        for (int i=0;i<=n-m;i++){
            int j;
            for(j=0;j<m;j++){
                if (needle[j]!=haystack[i+j]){
                    break;
                }
            }
           if(j==m){
            return i;
           }
        }
        return -1;
    }
};