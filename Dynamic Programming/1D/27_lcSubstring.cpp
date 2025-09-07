
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size(), m = s2.size();
        int dp[n+1][m+1];
        int maxLength = 0;
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return maxLength;
    }
};
// substring can end ar any index, so we keep track of maxLength whenever we find a match