class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int diff = it.first;
            int r = it.second.first, c = it.second.second;
            if(r==n-1 and c==m-1) return diff;
            for(int k=0; k<4; k++){
                int nr = r + dx[k], nc = c + dy[k];
                if(nr>=0 and nc>=0 and nr < n and nc < m){
                    int newEffort = max(abs(grid[r][c] - grid[nr][nc]), diff);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};