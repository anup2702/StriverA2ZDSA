class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> adj[V];
        
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                queue<pair<int, int>> q;
                q.push({i, -1});
                vis[i] = 1;
                while(!q.empty()){
                    auto [n, p] = q.front();
                    q.pop();
                    for(int neigh: adj[n]){
                        if(!vis[neigh]){
                            vis[neigh] = 1;
                            q.push({neigh, n});
                        } else if(p != neigh) return true;
                    }
                }
            }
        }
        return false;
    }
};