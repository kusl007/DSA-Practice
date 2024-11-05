// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if (left==NULL){
            return right;
        }
        if (right==NULL){
            return left;
        }
    ListNode* ans = new ListNode (-1);
    ListNode* mptr=ans;

    while(left && right){
        if (left->val<=right->val){
            mptr->next=left;
            left=left->next;
        }
        else{
            mptr->next=right;
            right=right->next;
        }
        mptr = mptr->next; 
    }
    if(left!=NULL){
        mptr->next=left;
    }
    if(right!=NULL){
        mptr->next=right;
    }
    return ans->next;


        
    }
};