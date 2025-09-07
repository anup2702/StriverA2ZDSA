class Solution {
public:
    bool isPalindrome(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int fn(int i, int n, string s) {
        if (i == n)
            return 0;
        int minCost = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + fn(j + 1, n, s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
    int minCut(string s) {
        int n = s.size();
        return fn(0, n, s) - 1; // partition after last el
    }
};



class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }

        vector<int> dp(n+1, 0);
        dp[n] = 0;  // base case

        for (int i = n-1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPal[i][j]) {
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1; // subtract 1 since last cut not needed
    }
};
