//Count the Reversals
//https://www.geeksforgeeks.org/problems/count-the-reversals0401/1


int countRev (string s) {
    // If the length of the string is odd, it's impossible to balance it
    if (s.length() % 2 != 0) {
        return -1;
    }
    
    stack<char> st;
    int count = 0;

    for (auto i : s) {
        if (!st.empty() && st.top() == '{' && i == '}') {
            st.pop();
        } else {
            st.push(i);
        }
    }

    // After processing, the stack will contain unbalanced braces
    int count0;

    while (!st.empty()) {
       char a=st.top();st.pop();
       char b=st.top();st.pop();
       (a==b)?count+=1:count+=2;
    }

    
    return count;
}