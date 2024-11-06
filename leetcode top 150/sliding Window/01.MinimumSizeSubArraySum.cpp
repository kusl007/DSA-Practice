// 209. Minimum Size Subarray Sum
//https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=INT_MAX;
        int sum=0;
        int s=0;
        int e=0;
        int n=nums.size();
        while(e<n){
            sum+=nums[e];
            e++;
            while(sum>=target){
                int len=e-s;
                minLen=min(len,minLen);
                sum-=nums[s];
                s++;
            }
        }
        if (minLen==INT_MAX) return 0;
        return minLen;
    }
};