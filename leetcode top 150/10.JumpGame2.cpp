//leetcode 45. Jump Game II
//https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int solveRE(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) {
            return 0;
        }
        
        int mini = INT_MAX;

        for (int jump = 1; jump <= nums[index]; jump++) {
            int nextIndex = index + jump;
            int result = solveRE(nums, nextIndex);
            if (result != INT_MAX) {
                mini = min(mini, 1 + result);
            }
        }

        return mini;
    }
    int solveMem(vector<int>& nums, int index,  vector<int>&dp) {
        if (index >= nums.size() - 1) {
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int mini = INT_MAX;

        for (int jump = 1; jump <= nums[index]; jump++) {
            int nextIndex = index + jump;
            int result = solveMem(nums, nextIndex,dp);
            if (result != INT_MAX) {
                mini = min(mini, 1 + result);
            }
            dp[index]=mini;
        }

        return mini;
    }
    int solveTD(vector<int>& nums) {
        int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int mini = INT_MAX;
        for (int jump = 1; jump <= nums[i]; jump++) {
            int nextIndex = i + jump;
            if (nextIndex < n && dp[nextIndex] != INT_MAX) {
                mini = min(mini, 1 + dp[nextIndex]);
            }
        }
        dp[i] = mini;
    }

    return dp[0] == INT_MAX ? 0 : dp[0];
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        if (n <= 1) return 0;
        // int result = solveRE(nums, 0);
        vector<int>dp(n,-1);
        // int result =solveMem(nums,0,dp);
        int result =solveTD(nums);
        return result == INT_MAX ? 0 : result;
    }
};