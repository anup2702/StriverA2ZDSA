// User function Template for C++

class Solution {
    
  public:
  
 long long int MOD = 1000000007;

    long long int topDown(int n) {
        if (n <= 1) return n;
        vector<long long int> dp(n + 1, -1);
        return helper(n, dp);
    }

    long long int helper(int n, vector<long long int> &dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        dp[n] = (helper(n - 1, dp) + helper(n - 2, dp)) % MOD;
        return dp[n];
    }

    long long int bottomUp(int n) {
        if (n <= 1) return n;
        vector<long long int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return dp[n];
    }
};