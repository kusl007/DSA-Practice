//11. Container With Most Water
//https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int maxArea(vector<int>& arr) {
        int lp=0;
        int rp=arr.size()-1;
        int maxArea=0;
        while(lp<rp){
            int width=rp-lp;
            int height=min(arr[lp],arr[rp]);
            int area=width*height;
            maxArea=max(area,maxArea);
            if (arr[lp]>arr[rp]){
                rp--;
            }
            else{
                lp++;
            }
        }
        return maxArea;
        
    }
};