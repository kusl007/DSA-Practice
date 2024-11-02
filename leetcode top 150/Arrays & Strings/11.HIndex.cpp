//leetcode 274. H-Index
//https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
          int s=0,e=citations.size()-1;
        int n=citations.size();
        int mid=s+(e-s)/2;
        while(s<=e){
            if(citations[mid]==n-mid){
                return citations[mid];
            }
            if(citations[mid]>n-mid){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;

        }
        return n-mid;
    }
};