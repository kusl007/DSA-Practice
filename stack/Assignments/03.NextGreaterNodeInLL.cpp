// 1019. Next Greater Node In Linked List
//https://leetcode.com/problems/next-greater-node-in-linked-list/description/ 


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        // Traverse the linked list and store values in the vector
        while (head) {
            ll.push_back(head->val);
            head = head->next;
        }
        
        stack<int> st;
        vector<int> ans(ll.size(), 0);

        // Traverse the list from left to right
        for (int i = 0; i < ll.size(); i++) {
            // Resolve the next greater element for nodes in the stack
            while (!st.empty() && ll[i] > ll[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = ll[i];
            }
            st.push(i); // Push the index of the current element
        }
        return ans;
    }
};
