//gfg Flattening a Linked List
//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1



class Solution {
public:
    // Function to merge two sorted linked lists
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* ans;
        if (a->data < b->data) {
            ans = a;
            a->bottom = merge(a->bottom, b);
        } else {
            ans = b;
            b->bottom = merge(a, b->bottom);
        }
        return ans;
    }

    // Function to flatten the linked list
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;

        // Recursively flatten the next part of the list and merge
        return merge(root, flatten(root->next));
    }
};
