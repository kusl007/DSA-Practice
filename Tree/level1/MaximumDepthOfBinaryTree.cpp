//104. Maximum Depth of Binary Tree


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int left=maxDepth(root->left)+1;
        int right=maxDepth(root->right)+1;
        return max(left,right);
    }
};