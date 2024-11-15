//1047. Remove All Adjacent Duplicates In String
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/



class Solution {
public:
    string removeDuplicates(string s) {
       stack<char> st;
       string ans = "";

       for (int i = 0; i < s.length(); i++) {
           if (!st.empty() && s[i] == st.top()) {
               st.pop();  // Remove the duplicate
           } else {
               st.push(s[i]);  // Push the current character
           }
       }

       // Build the result string from the stack
       while (!st.empty()) {
           ans = st.top() + ans;
           st.pop();
       }

       return ans;
    }
};