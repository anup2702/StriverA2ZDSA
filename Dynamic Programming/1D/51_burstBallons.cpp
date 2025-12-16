class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+2, 1);
        for(int i=0; i<n; i++) arr[i+1] = nums[i];
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int win = 1; win<=n; win++){
            for(int l=1; l+win-1<=n; l++){
                int r = l+win-1;
                for(int i=l; i<=r; i++){
                    dp[l][r] = max(dp[l][r], arr[l-1]*arr[i]*arr[r+1]+dp[l][i-1]+dp[i+1][r]);
                }
            }
        }
        return dp[1][n];
    }
};