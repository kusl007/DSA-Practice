//leetcode 532
//https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        set<pair<int,int>>ans;
        while(j<nums.size()){
            int diff =nums[j]-nums[i];
            if(diff==k){
                ans.insert({nums[i],nums[j]});
                ++i,++j;
            }
            else if (diff>k){
                ++i;
            }
            else ++j;
            if(i==j){
                j++;
            }

        }
        
    return ans.size();
    }
};



// ***********************   method 2   ******************************

class Solution {
public:

int bs (vector<int>&nums,int start,int x){
    int end =nums.size()-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(nums[mid]==x){
            return mid;
        }
        else if(x>nums[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            // a[i]
            // search a[i]+k
            if (bs (nums,i+1,nums[i]+k) !=-1){
                ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();
    }
};