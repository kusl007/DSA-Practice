// leetcode 189. Rotate Array
//https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    void reverse(vector<int>& nums, int s, int e) {
        while (s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k <= 0) { return; }
        k = k % n;
        if (k == 0) return;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
