class Solution {
public:
    int findTheCity(int v, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(v, vector<int>(v, 1e8));
        for(vector<int> edge: edges){
            int u=edge[0], v=edge[1],w=edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int i=0; i<v; i++) dist[i][i] = 0;

        for(int k=0; k<v; k++){
            for(int i=0; i<v; i++){
                for(int j=0; j<v; j++){
                    if(dist[i][k] != 1e8 and dist[k][j] != 1e8){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }     
        }

        int ans = -1, reach = 1e8;
        for(int i=0; i<v; i++){
            int cnt = 0;
            for(int j=0; j<v; j++){
                if(i != j and dist[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= reach){
                reach = cnt;
                ans = i;
            }
        }
        return ans;
    }
};