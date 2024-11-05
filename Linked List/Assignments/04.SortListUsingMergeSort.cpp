//148. Sort List
// https://leetcode.com/problems/sort-list/description/



class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow; 
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL) return right;
        if (right == NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while (left && right) {
            if (left->val <= right->val) {
                mptr->next = left;
                left = left->next;
            } else {
                mptr->next = right;
                right = right->next;
            }
            mptr = mptr->next;
        }

        if (left != NULL) {
            mptr->next = left;
        }
        if (right != NULL) {
            mptr->next = right;
        }

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Split the list into two halves
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // Recursively sort the two halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return merge(left, right);
    }
};