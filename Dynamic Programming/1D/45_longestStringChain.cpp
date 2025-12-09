class Solution {
public:

    bool checkDiff(string &a, string &b) {
        if (a.size() != b.size() + 1)return false;

        int i = 0, j = 0;
        bool skipped = false;
        while (i < a.size()) {
            if (j < b.size() && a[i] == b[j]) {
                i++; j++;
            } 
            else {
                if (skipped) return false;
                skipped = true;
                i++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(),
        [](const string &a, const string &b){
                 return a.size() < b.size();
             });

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkDiff(words[i], words[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
