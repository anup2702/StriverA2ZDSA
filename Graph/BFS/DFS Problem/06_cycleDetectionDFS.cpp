class Solution {
  public:
  
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for(int neigh : adj[node]) {
            if(!vis[neigh]) {
                if(dfs(neigh, node, adj, vis)) return true;
            }
            else if(neigh != parent) {
                return true; 
            }
        }
        return false;
    }
    
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
               if(dfs(i, -1, adj, vis)) return true;
            }
        }
    
        return false;
    }
};