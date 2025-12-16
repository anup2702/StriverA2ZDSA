class Solution {
public:
    int fn(int idx, vector<int>& arr, int k, vector<int>& memo, int n){
        if(idx == n) return 0;
        if(memo[idx]!=-1) return memo[idx];
        int len = 0, maxi = INT_MIN, sum = 0, maxAns = INT_MIN;
        for(int i=idx; i<min(n, idx+k); i++){
            len++; maxi = max(maxi, arr[i]);
            sum = (len*maxi) + fn(i+1, arr,k, memo, n);
            maxAns = max(maxAns, sum);
        }
        return memo[idx] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> memo(n, -1);
        return fn(0, arr, k, memo, n);
    }
};


// tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int j=n-1; j>=0; j--){
            int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
            for(int i=j; i<min(n, j+k); i++){
                len++; maxi = max(maxi, arr[i]);
                int sum = (len*maxi) + dp[i+1];
                maxAns = max(maxAns, sum);
            }
            dp[j] = maxAns;
        }
        return dp[0];
    }
};