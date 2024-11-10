// 61. Rotate List
// https://leetcode.com/problems/rotate-list/description/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        
        // Calculate the length of the list and get the tail
        ListNode* tail = head;
        int count = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            count++;
        }
        
        // Use modulo to minimize unnecessary rotations
        k = k % count;
        if (k == 0) {
            return head; // No rotation needed
        }
        
        // Find the new tail at (count - k - 1) and new head at (count - k)
        ListNode* newTail = head;
        for (int i = 1; i < count - k; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        
        // Rotate the list
        newTail->next = NULL;
        tail->next = head;
        
        return newHead;
    }
};