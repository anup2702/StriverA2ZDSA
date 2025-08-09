class Solution {
public:

    int solve(int m, int n, vector<vector<int>> grid, vector<vector<int>>& memo){
        if(m == 0 and n==0) return grid[0][0];
        if(m < 0 or n < 0) return INT_MAX;
        if(memo[m][n] != -1) return memo[m][n];

        int up = solve(m-1, n, grid, memo);
        int left = solve(m, n-1, grid, memo);

        if(up != INT_MAX) up += grid[m][n];
        if(left != INT_MAX) left += grid[m][n];

        return memo[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, memo);
    }
};



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    dp[i][j] = grid[0][0];
                else {
                    int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j - 1] : INT_MAX;

                    if (up != INT_MAX)
                        up += grid[i][j];
                    if (left != INT_MAX)
                        left += grid[i][j];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};