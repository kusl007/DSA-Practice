//leetcode =>   852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
int findPeakIndex(vector<int>arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-e)/2;

    }
    return s;
}
    int peakIndexInMountainArray(vector<int>& arr) {
        return findPeakIndex(arr);
        
    }
};