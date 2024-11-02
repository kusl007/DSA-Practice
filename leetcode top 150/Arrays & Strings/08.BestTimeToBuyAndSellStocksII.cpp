//leetcode 122. Best Time to Buy and Sell Stock II
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:

int solve(vector<int>& prices, int i, int buy) {
    if(i >= prices.size()) return 0; // Base case: no more days to trade
    
    int profit = 0;
    if(buy == 1) {
        // Case when you buy the stock
        int buyProfit = -prices[i] + solve(prices, i + 1, 0); // buy and move to the next day with sell option
        int skipProfit = solve(prices, i + 1, 1); // skip and still have buy option
        profit = max(buyProfit, skipProfit);
    } else {
        // Case when you sell the stock
        int sellProfit = prices[i] + solve(prices, i + 1, 1); // sell and move to the next day with buy option
        int skipProfit = solve(prices, i + 1, 0); // skip and keep sell option
        profit = max(sellProfit, skipProfit);
    }

    return profit;
}
int solveMemo(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
    if(i >= prices.size()) return 0;

    if(dp[i][buy] != -1) return dp[i][buy]; // Check memo table

    int profit = 0;
    if(buy == 1) {
        int buyProfit = -prices[i] + solveMemo(prices, i + 1, 0, dp);
        int skipProfit = solveMemo(prices, i + 1, 1, dp);
        profit = max(buyProfit, skipProfit);
    } else {
        int sellProfit = prices[i] + solveMemo(prices, i + 1, 1, dp);
        int skipProfit = solveMemo(prices, i + 1, 0, dp);
        profit = max(sellProfit, skipProfit);
    }

    return dp[i][buy] = profit;
}
int solveBottomUp(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));  // Initialize dp array

    for(int i = n - 1; i >= 0; i--) {
        for(int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if(buy == 1) {
                // Buying the stock
                int buyProfit = -prices[i] + dp[i + 1][0]; // Move to next day with sell option
                int skipProfit = dp[i + 1][1]; // Skip buying
                profit = max(buyProfit, skipProfit);
            } else {
                // Selling the stock
                int sellProfit = prices[i] + dp[i + 1][1]; // Move to next day with buy option
                int skipProfit = dp[i + 1][0]; // Skip selling
                profit = max(sellProfit, skipProfit);
            }

            dp[i][buy] = profit;  // Store the result in dp
        }
    }

    return dp[0][1];  // Starting from day 0 with the option to buy
}
int solveSO(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int>(2, 0));  // Initialize dp array

    for(int i = n - 1; i >= 0; i--) {
        for(int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if(buy == 1) {
                // Buying the stock
                int buyProfit = -prices[i] + dp[1][0]; // Move to next day with sell option
                int skipProfit = dp[1][1]; // Skip buying
                profit = max(buyProfit, skipProfit);
            } else {
                // Selling the stock
                int sellProfit = prices[i] + dp[1][1]; // Move to next day with buy option
                int skipProfit = dp[1][0]; // Skip selling
                profit = max(sellProfit, skipProfit);
            }
            dp[0][buy] = profit;  // Store the result in dp
        }
        dp[1] = dp[0];  // Move current state to the next day
    }

    return dp[0][1];  // Starting from day 0 with the option to buy
}



    int maxProfit(vector<int>& prices) {
        // return solve(prices,0,1);
        // int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solveMemo(prices,0,1,dp);
        // return solveBottomUp(prices);
        return solveSO(prices);
        
    
}
};