class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(b.begin(), b.end());
        int n = s.size(), m = b.size();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// So, if "babcbab" is a palindrome in s, it must also appear in reverse(s)`.