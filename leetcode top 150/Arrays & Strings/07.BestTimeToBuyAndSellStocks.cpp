//leetcode 121.Best Time to Buy and Sell Stock
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(auto i:prices){
            minPrice=min(minPrice,i);
            profit=i-minPrice;
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
        
    }
};