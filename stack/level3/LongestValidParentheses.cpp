//32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> st;
        st.push (-1);
        int len=0;
        int max_len =0;


        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            st.push(i);
            
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else {
                    len=i-st.top();
                    max_len=max(len,max_len);

                }
                
            }
        }
        return max_len;
        
    }
};