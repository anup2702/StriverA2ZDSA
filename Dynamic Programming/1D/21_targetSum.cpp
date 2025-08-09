class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if (sum < abs(d) || (sum + d) % 2 != 0 || (sum + d) < 0) return 0;

        int target = (sum + d)/2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                // Exclude current
                dp[i][j] = dp[i - 1][j];
                // Include current if possible
                if (j >= arr[i - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]);
                }
            }
        }

        return dp[n][target];
    }
};