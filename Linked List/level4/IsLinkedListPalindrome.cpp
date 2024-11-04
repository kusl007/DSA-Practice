// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/



class Solution {
public:
   ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        // Use two pointers to find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        slow = reverse(slow);

        // Compare the first half and the reversed second half
        ListNode* temp = head;
        while (slow != NULL) {
            if (temp->val != slow->val) return false;
            temp = temp->next;
            slow = slow->next;
        }

        return true;
    }
};