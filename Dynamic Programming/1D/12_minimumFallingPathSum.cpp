/*class Solution {
public:
    int fn(int i, int j, vector<vector<int>>& matrix,
           vector<vector<int>>& memo) {
        if (j <= 0 or j >= matrix.size())
            return 1e9;
        if (i == 0)
            return matrix[i][j];
        if (memo[i][j] != -1)
            return memo[i][j];

        int u = matrix[i][j] + fn(i - 1, j, matrix, memo);
        int ld = matrix[i][j] + fn(i - 1, j - 1, matrix, memo);
        int rd = matrix[i][j] + fn(i - 1, j + 1, matrix, memo);

        return memo[i][j] = min({u, ld, rd});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        for (int j = 0; j < n; j++) {
            mini = min(mini, fn(n - 1, j, matrix, memo));
        }
        return mini;
    }
};

tc - O(n^2) sc - O(n^2 + n)
only recursion tc - (3^n)
*/


/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j], rd = matrix[i][j];
                if(j-1 >= 0) ld += dp[i-1][j-1];
                else ld += 1e8;
                if(j+1 < n) rd += dp[i-1][j+1];
                else rd += 1e8;
                dp[i][j] = min({u, ld, rd});
            }
        }
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};
*/

/*
  Space optimization

  class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0), curr(n, 0);

        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j], rd = matrix[i][j];
                if(j-1 >= 0) ld += prev[j-1];
                else ld += 1e8;
                if(j+1 < n) rd += prev[j+1];
                else rd += 1e8;
                curr[j] = min({u, ld, rd});
            }
            prev = curr;
        }
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini,prev[j]);
        }
        return mini;
    }
};
*/