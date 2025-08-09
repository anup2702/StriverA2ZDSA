class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            int minStep = INT_MAX;
            for(int j=1; j<=k; j++){
                if(i-j>=0){
                    int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                    minStep = min(jump, minStep);
                }
            }
            dp[i] = minStep;
        }
        return dp[n-1];
    }
};