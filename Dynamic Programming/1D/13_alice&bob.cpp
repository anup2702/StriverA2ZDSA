/**
class Solution {
  public:
  
  int f(int i, int j1, int j2, vector<vector<int>>& grid, int r, int c,  vector<vector<vector<int>>>& memo){
      if(j1 < 0 or j2 < 0 or j1 >= c or j2 >= c) return -1e8;
      if(i == r-1){
          if(j1 == j2) return grid[i][j1];
          else return grid[i][j1] + grid[i][j2];
      }
      if(memo[i][j1][j2] != -1) return memo[i][j1][j2];
      
      int maxi = -1e8;
      for(int dj1 = -1; dj1 <= 1; dj1++){
          for(int dj2 = -1; dj2 <= 1; dj2++){
              int value = 0;
              if(j1 == j2) value += grid[i][j1];
              else value += grid[i][j1] + grid[i][j2];
              value += f(i+1, j1+dj1, j2+dj2, grid, r, c, memo);
              maxi = max(maxi, value);
              memo[i][j1][j2] = maxi;
          }
      }
      return maxi;
      
  }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m-1, grid, n, m, memo);
         
    }
};
  tc - O(3^n)
*/