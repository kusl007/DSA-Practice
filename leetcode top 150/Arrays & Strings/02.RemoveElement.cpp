//leetcode 27. Remove Element
//https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }

        int j = nums.size() - 1;
        int i = 0;

        while (i <= j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                j--;
            } else {
                i++;
            }
        }
    int k=nums.size()-1;
        while(k>=0&& nums[k]==val){
            nums.pop_back();;
            k--;
        }

        return nums.size();
    }
};
