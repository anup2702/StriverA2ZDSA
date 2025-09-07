class Solution {
  public:
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int l=2; l<n; l++){ // len of chain
            for(int i=1; i<n-l+1; i++){ // st idx of subchain
                int j = i+l-1;  // end idx of chain
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) { // partition pt
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n-1];
        
    }
};