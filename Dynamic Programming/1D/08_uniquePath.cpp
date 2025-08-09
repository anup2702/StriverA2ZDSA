/*
class Solution {
public:
    int solve(int m, int n) {
        if (m == 0 and n == 0)
            return 1;
        if (m < 0 or n < 0)
            return 0;

        int up = solve(m - 1, n);
        int left = solve(m, n - 1);
        return up + left;
    }

    int uniquePaths(int m, int n) { return solve(m - 1, n - 1); }

    tc - O(2^mn)
    sc - path len = m-1 + n-1
};
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // int dp[m][n];
        // for(int i=0; i<m; i++) dp[i][0] = 1;
        // for(int j=0; j<n; j++) dp[0][j] = 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
 int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 and j==0) curr[j] = 1;
                else{
                    if(i > 0) int up = prev[j];
                    if(j > 0) int left = curr[j-1]
                    temp[j] = up + left;
                }
            }
            prev = curr;
        }
        return ;
    }
*/