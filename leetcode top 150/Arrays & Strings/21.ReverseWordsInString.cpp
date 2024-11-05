// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans ="";
        reverse(s.begin(),s.end());
        for (int i=0;i<n;i++){
            string word="";
            while(i <n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if (word.length()>0){
                ans+= " "+word;
            }
        }
        return ans.substr(1);
    }

};