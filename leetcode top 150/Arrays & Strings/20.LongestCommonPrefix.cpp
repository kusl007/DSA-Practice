// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/submissions/1442641925/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
         if (arr.empty()) return ""; 
        string ans;
        int n=arr.size();
        for(int i =0;i<arr[0].length();i++){
            char ch=arr[0][i];
            bool match =true;
            for(int j=1;j<n;j++){
                if (arr[j].size()<=i||ch!=arr[j][i]){
                    match=false;
                    break;
                }
            }
            if (match) ans.push_back(ch);
            else break;

        }
        return ans;
    }
};