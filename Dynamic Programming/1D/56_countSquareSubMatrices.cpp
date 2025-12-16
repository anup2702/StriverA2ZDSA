class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0) dp[i][j] = matrix[0][j];
                else if(j==0) dp[i][j] = matrix[i][0];
                else if(matrix[i][j]==0) dp[i][j] = 0;
                else dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
            }
        }
        int total = 0;
        for(int i=0; i<n; i++){
            total += accumulate(dp[i].begin(), dp[i].end(), 0);
        }
        return total;
    }
};