// 25.Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/


class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        int len = getLength(head);
        if (k > len) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* right = nullptr;
        int count = 0;

        while (count < k ) {
            right = curr->next;
            curr->next = prev;
            prev = curr;
            curr = right;
            count++;
        }

        if (right != nullptr) {
            head->next = reverseKGroup(right, k);
        }

        return prev;
    }
};
