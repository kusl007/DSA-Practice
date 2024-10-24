//leetcode 14. Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        string first=strs[0];
        for(int i=0;i<first.length();i++){
            char ch=first[i];
            bool match=true;

            for(int j=1;j<strs.size();j++){
                if( strs[j].length()<i || ch != strs[j][i]){
                    match=false;
                    break;                
            }
            }
        

        if(match==false){
           break;
        }
           else{
            ans.push_back(ch);
           }
        
        }
        return ans;
    }


};


// **********  or **********
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) return ""; 
        string ans;
        int i=0;

        while(true){
            char curr_ch=0;
            for(auto str:strs){
                if(i>=str.size()){
                    curr_ch=0;
                    break;
                }
                if(curr_ch==0){
                    curr_ch=str[i];
                }
                else if(curr_ch!=str[i]){
                    curr_ch=0;
                    break;
                }
            }
            if(curr_ch==0){
                break;
            }
            ans.push_back(curr_ch);
            i++;

        }
        return ans;
    }
};