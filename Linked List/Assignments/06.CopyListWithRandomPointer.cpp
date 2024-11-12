//138. Copy List with Random Pointer
//https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helperOld(Node* head,unordered_map<Node*,Node*> &mp) {
         if(!head)
         return head;

         Node * newHead=new Node(head->val);
          mp[head]=newHead;
          newHead->next=helperOld(head->next,mp);
          if(head->random){
            newHead->random=mp[head->random];
          }
          return newHead;


    }
     Node* helperNew(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone each node and insert it after the original node
        Node* it = head;
        while (it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = clonedNode->next;  // Move to the next original node
        }

        // Step 2: Assign random pointers to the cloned nodes
        it = head;
        while (it) {
            if (it->random) {
                it->next->random = it->random->next;
            } else {
                it->next->random = nullptr;
            }
            it = it->next->next;  // Move to the next original node
        }

        // Step 3: Detach the cloned list from the original list
        it = head;
        Node* clonedHead = head->next;
        while (it) {
            Node* clonedNode = it->next;
            it->next = clonedNode->next;
            if (clonedNode->next) {
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;  // Move to the next original node
        }

        return clonedHead;
    }

    Node* copyRandomList(Node* head) {
        // unordered_map<Node*,Node*>mp; //old to new node mapping
        // return helperOld(head,mp);
        return helperNew(head);

        
    }
};