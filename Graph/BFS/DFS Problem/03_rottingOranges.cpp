class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;

        int time = 0;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

        while(!q.empty()){
            int size = q.size();
            bool rooten = false;
            for(int i=0; i<size; i++){
                auto [x, y] = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rooten = true;
                    }
                }
            }
            if(rooten) time++;
        }

        return fresh == 0 ? time: -1;
    }
};