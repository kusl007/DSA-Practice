// 543. Diameter of Binary Tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int opt1=diameterOfBinaryTree(root->left);
        int opt2=diameterOfBinaryTree(root->right);
        int opt3=maxDepth(root->left)+maxDepth(root->right);
        return max(opt1,max(opt2,opt3));

    }
};