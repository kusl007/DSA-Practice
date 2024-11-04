// leetcode 42. Trapping Rain Water
//https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int leftMax=0,rightMax=0,total=0,l=0,r=n-1;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(arr[l]<leftMax){
                    total+=leftMax-arr[l];
                    l++;
                }
                else{
                    leftMax=arr[l];
                    l++;
                }
            }
            else{
                if(arr[r]<rightMax){
                    total+=rightMax-arr[r];
                    r--;
                }
                else{
                    rightMax=arr[r];
                    r--;
                }
            }
        }
        return total;
        
    }
};