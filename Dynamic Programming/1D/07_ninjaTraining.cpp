/*
class Solution {
  public:
  int solve(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& memo){
      if(day==0){
          int maxi = 0;
          for(int i=0; i<=2; i++){
              if(i != last) maxi = max(maxi, arr[0][i]);
          }
          return maxi;
      }
      if(memo[day][last] != -1) return memo[day][last];
      
      int maxi = 0;
      for(int i=0; i<=2; i++){
          if(i != last){
            int points = arr[day][i] + solve(day-1, i, arr, memo); 
            maxi = max(maxi, points);
          }
      }
      return memo[day][last] = maxi;
  }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(4, -1));
        return solve(n-1, 3, arr, memo);
    }
};
*/

/*
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][1], arr[0][3]);
        dp[0][3] = max({arr[0][1], arr[0][2], arr[0][0]});
        
        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                dp[day][last] = 0;
                for(int task = 0; task <= 2; task++){
                    if(task != last){
                        int points = arr[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }
        
        return dp[n-1][3];
        
    }
};
*/

/*
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<int> prev(4);
        
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][1], arr[0][3]);
        prev[3] = max({arr[0][1], arr[0][2], arr[0][0]});
        
        for(int day = 1; day < n; day++){
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++){
                temp[last] = 0;
                for(int task = 0; task <= 2; task++){
                    if(task != last){
                        temp[last] = max(temp[last], arr[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;
        }
        
        return prev[3];
        
    }
};
*/


class Solution {
public:
    int uniquePaths(int m, int n) {
        // int dp[m][n];
        // for(int i=0; i<m; i++) dp[i][0] = 1;
        // for(int j=0; j<n; j++) dp[0][j] = 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};