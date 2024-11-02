// leetcode  206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* &prev,ListNode* &curr) {
        //base case
        if(curr==NULL){
            return prev;
        }
        ListNode* forward=curr->next;
        curr->next=prev;
        reverse(curr,forward);

    }

    ListNode* reverseList(ListNode* head) {
        if (head==NULL){
            return head;
        }

        ListNode* prev=NULL;
        ListNode* curr=head;
       

        head=reverse(prev,curr);
        

        return head;


        
    }
};