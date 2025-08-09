class Solution {
  public:
    int minimumEnergy(vector<int>& a, int n) {
        // Code here
        vector<int> dp(n,0);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int fs = dp[i-1] + abs(a[i]-a[i-1]);
            int ss = INT_MAX;
            if(i > 1) ss = dp[i-2] + abs(a[i]-a[i-2]);
            dp[i] = min(fs,ss);
        }
        return dp[n-1];
    }
};


// Space Optimization
class Solution {
  public:
    int minimumEnergy(vector<int>& a, int n) {
        // Code here
        int prev2 = 0, prev = 0;
        for(int i=1;i<n;i++){
            int fs = prev + abs(a[i]-a[i-1]);
            int ss = INT_MAX;
            if(i > 1) ss = prev2 + abs(a[i]-a[i-2]);
            
            int curr = min(fs,ss);
            prev2 = prev;
            prev = curr;
        }
        return dp[n-1];
    }
};
