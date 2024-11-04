//83. Remove Duplicates from Sorted List
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;

      ListNode* curr = head;
        while(curr!=NULL){
            ListNode* nextNode = curr->next; 
            while (nextNode != NULL && nextNode->val == curr->val) {
                nextNode = nextNode->next; // Move to the next unique node
            }
        curr->next = nextNode;
        curr = nextNode;
        }
    return head;
    }
};




// **************** OR *****************

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        if(head->next==NULL) return head;

        ListNode* curr=head;
        while(curr!=NULL){
            if( curr->next!=NULL && curr->val==curr->next->val){
                ListNode* temp =curr->next;
                    curr->next=curr->next->next;
                    temp->next=NULL;
                    delete temp;
            }
            else{
                curr=curr->next;
            }
        }
    return head;
    }
};