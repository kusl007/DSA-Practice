// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/description/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

    while(fast != NULL && fast->next != NULL){
            fast=fast->next;
            if ( fast->next != NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};