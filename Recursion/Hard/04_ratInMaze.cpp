class Solution {
  public:
    vector<string> res;
    vector<vector<int>> vis;
  
    void dfs(vector<vector<int>>& maze, int n, int i, int j, string path){
        if(i == n-1 and j==n-1){
            res.push_back(path);
            return;
        }
        if(i<0 or j<0 or i>=n or j>=n) return;
        if(maze[i][j]==0 or vis[i][j] == 1) return;
        
        vis[i][j] = 1;

        dfs(maze, n, i+1, j, path+'D');
        dfs(maze, n, i, j-1, path+'L');
        dfs(maze, n, i, j+1, path+'R');
        dfs(maze, n, i-1, j, path+'U');
        vis[i][j] = 0;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        res.clear();
        if(maze[n-1][n-1]==0 or maze[0][0] == 0) return res;
        vis = vector<vector<int>>(n, vector<int>(n, 0));
        dfs(maze, n, 0, 0, "");
        
        return res;
    }
};