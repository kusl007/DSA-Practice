//lc 236. Lowest Common Ancestor of a Binary Tree


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL)
            return NULL;

        //check for p and q;
        if(root->val == p->val)
            return p;
        if(root->val == q->val)
            return q;
        
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL)
            return NULL;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else{
            return root;
        }
    }
};