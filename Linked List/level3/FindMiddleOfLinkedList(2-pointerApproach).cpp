//tortoise algo
//876. Middle of the Linked List
//https://leetcode.com/problems/middle-of-the-linked-list/description/


class Solution {
public:
    ListNode* find(ListNode* slow,ListNode* fast) {
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }

        }
        return slow;
    }
    ListNode* middleNode(ListNode* head) {
       return find (head,head);
        
        
    }
};