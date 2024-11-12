//Delete N nodes after M nodes of a linked list
//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1


 class Solution {
public:
    Node* linkdelete(Node* head, int n, int m) {
        if (!head) return head;

        Node* current = head;

        // Process the list by iterating and deleting `n` nodes after skipping `m` nodes
        while (current) {
            // Skip `m-1` nodes
            for (int i = 1; i < m && current; i++) {
                current = current->next;
            }
            
            // If reached the end of the list, break
            if (!current) break;

            // Set the pointer to the node from which deletion starts
            Node* temp = current->next;

            // Delete `n` nodes
            for (int i = 0; i < n && temp; i++) {
                Node* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            }

            // Link the current node to the node after the deleted nodes
            current->next = temp;

            // Move to the next segment
            current = temp;
        }

        return head;
    }
};
