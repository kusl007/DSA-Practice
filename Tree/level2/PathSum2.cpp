//113. Path Sum II

class Solution {
public:
    void solve(TreeNode* root, int targetSum , int &currSum, vector<int> &path, vector<vector<int> > &ans) {
       // cout << "Curr Sum " << currSum << endl;
        //base case
        if(root == NULL) {
            return;
        }
        //Leaf Node
        if(root->left == NULL && root->right == NULL) {
            //include curr node
            path.push_back(root->val);
            currSum += root->val;
            //check for target sum
            if(currSum == targetSum) {
                ans.push_back(path);
            }
            //exclude 
            path.pop_back();
            currSum -= root->val;
            return;
        }

        //include curr node
        path.push_back(root->val);
        currSum += root->val;

        solve(root->left, targetSum, currSum, path, ans);
        solve(root->right, targetSum, currSum, path, ans);

        //backltrack
        path.pop_back();
        currSum -= root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int> > ans;
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum, sum, temp, ans);
        return ans;
        
    }







};