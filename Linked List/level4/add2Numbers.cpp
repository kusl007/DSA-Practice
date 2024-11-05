//2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/description/
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* right;

        while (curr != NULL) {
            right = curr->next;
            curr->next = prev;
            prev = curr;
            curr = right;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        // Adding nodes where both l1 and l2 are not NULL
        while (l1 != NULL && l2 != NULL) {
            int sum = carry + l1->val + l2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);

            if (ansHead == NULL) {
                ansHead = newNode;
                ansTail = newNode;
            } else {
                ansTail->next = newNode;
                ansTail = newNode;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        // Adding remaining nodes from l1
        while (l1 != NULL) {
            int sum = carry + l1->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l1 = l1->next;
        }

        // Adding remaining nodes from l2
        while (l2 != NULL) {
            int sum = carry + l2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l2 = l2->next;
        }

        // If there is a remaining carry
        while (carry != 0) {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }

        return ansHead;
    }
};