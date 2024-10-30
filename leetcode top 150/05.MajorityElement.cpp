//169. Majority Element
//https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // sort
        sort(nums.begin(), nums.end());
         
        // freq count
        int freq = 1;
        int ans = nums[0];
        for (int i = 1; i < n; i++) {  // Changed to start from 1
            if (nums[i] == nums[i - 1]) {
                freq++;
            } else {
                freq = 1;
                ans = nums[i];
            }
            if (freq > n / 2) {  // Use `>=` for majority element check
                return ans;
            }
        }
        return ans;  // Return the last found answer
    }
};