class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        // 0 cuts n
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));
        for (int i = m; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                if (i > j) continue;
                int mini = INT_MAX;
                for (int idx = i; idx <= j; idx++) {
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[idx+1][j] + dp[i][idx-1];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m];
    }
};

// dp[i][j] = minimum cost to cut segment between cuts[i−1] and cuts[j+1]