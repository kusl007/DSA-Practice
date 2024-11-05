//160. Intersection of Two Linked Lists
//https://leetcode.com/problems/intersection-of-two-linked-lists/description/



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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = findLength(headA);
        int l2 = findLength(headB);
        int diff = abs(l1 - l2);

        // Move the pointer of the longer list forward by the difference in lengths
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (diff > 0) {
            if (l1 > l2) {
                tempA = tempA->next;
            } else {
                tempB = tempB->next;
            }
            diff--;
        }

        // Traverse both lists and check for intersection
        while (tempA != NULL ) {
            if (tempA == tempB) {  // Check if the nodes themselves are the same
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;  // Return NULL if no intersection is found
    }
};
