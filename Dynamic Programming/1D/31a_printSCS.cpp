class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int dp[n+1][m+1];

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string res = "";
        while(n > 0 and m > 0){
            if(s1[n-1] == s2[m-1]){
                res += s1[n-1];
                n--;
                m--;
            } else {
                if(dp[n][m-1] > dp[n-1][m]){
                    res += s2[m-1];
                    m--;
                } else {
                    res += s1[n-1];
                    n--;
                }
            }
        }

        while(n > 0){
            res += s1[n-1];
            n--;
        }

        while(m > 0){
            res += s2[m-1];
            m--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
