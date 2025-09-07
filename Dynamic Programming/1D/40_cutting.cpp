class Solution {
public:
int fn(int i, int j, vector<int>& cuts){
    if(i>j) return 0;
    int mini = INT_MAX;
    for(int idx = i; idx <= j; idx++){
        int cost = (cuts[j+1] - cuts[i-1]) + fn(i, idx-1, cuts) + fn(idx+1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        return fn(1, m, cuts);
    }
};



class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
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