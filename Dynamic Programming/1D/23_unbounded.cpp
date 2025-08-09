class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        int dp[n+1][capacity+1];
        
        for(int i=0; i<= n; i++){
            for(int j=0; j<=capacity; j++){
                if(j==0) dp[i][j] = 0;
                else if(i==0) dp[i][j] = 0;
                else if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1]+ dp[i][j-wt[i-1]], dp[i-1][j]);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][capacity];
    }
};

