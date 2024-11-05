//19. Remove Nth Node From End of List
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/



class Solution {
public:
    int findLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = findLength(head);
        
        // Handle the case where we need to remove the head
        if (n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* prev = head;
        int i = 1; // Start from 1 since we're stopping at (length - n - 1) node
        while (i < length - n) {
            prev = prev->next;
            i++;
        }
        
        ListNode* curr = prev->next;
        prev->next = curr->next;
        delete curr;
        
        return head;
    }
};
