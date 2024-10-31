//leetcode 55. Jump Game
//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=0;
         for(int i=0;i<n;i++){
            if(i>maxIndex){
                return false;
            }
            maxIndex=max(maxIndex,i+nums[i]);

         }
         return true;
        
    }
};