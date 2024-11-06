// 167. Two Sum II - Input Array Is Sorted
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int s=0;
        int e=arr.size()-1;
        vector<int>ans;
        while(s<e){
            if (arr[s]+arr[e]==target){
                ans.push_back(s+1);
                ans.push_back(e+1);
                s++;
                e--;
                break;


            }
            else if(arr[s]+arr[e]>target){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
        
    }
};