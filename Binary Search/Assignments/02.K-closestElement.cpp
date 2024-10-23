// leetcode 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/description/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s=0,e=arr.size()-1;
        vector<int>ans;
        while(e-s>=k){
            if((x-arr[s])>(arr[e]-x)){
                s++;
            }
            else e--;
        }
        while(s<=e){
            ans.push_back(arr[s]);
            s++;
        }
    return ans ;
    }
};


// *****************************************************
// or can return 
   return vector<int>(arr.begin()+s,arr.begin()+e+1);
   