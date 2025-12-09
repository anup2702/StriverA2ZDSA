class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]) return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        q.push({1, {0, 0}});
        vis[0][0] = 1;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int dis = it.first;
            int r = it.second.first, c = it.second.second;
            if(r==n-1 and c==n-1) return dis;

            for(int k=0; k<8; k++){
                int nr = r + dx[k], nc = c + dy[k];
                if(nr>=0 and nc>=0 and nr < n and nc < n and grid[nr][nc] == 0 and !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({dis+1,{nr, nc}});
                }
            }
        }
        return -1;
    }
};