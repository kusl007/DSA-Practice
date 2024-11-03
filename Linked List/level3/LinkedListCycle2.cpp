//142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/description/


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                // Cycle detected, find the cycle start
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // Cycle start
            }
        }
        
        return NULL;  // No cycle
    }
};
