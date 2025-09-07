class Solution {
public:
    int fn(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy == 0){
            profit = max(0 + fn(prices, idx+1, 0, dp), -prices[idx] + fn(prices, idx+1, 1, dp));
        } 
        else{
            profit = max(0 + fn(prices, idx+1, 1, dp), prices[idx] + fn(prices, idx+1, 0, dp));
        }
        return dp[idx][buy] = profit; 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fn(prices, 0, 0, dp);
    }
};


long getMaximumProfit(long *Arr, int n) {
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    dp[n][0] = dp[n][1] = 0;
    long profit;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) {
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            } if (buy == 1) {
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}