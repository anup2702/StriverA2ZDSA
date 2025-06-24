class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<int> dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, adj, vis, ls);
        }
        return ls;
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n,0);
        vector<int> list;
        dfs(0, adj, vis, list);
        return list;
    }
};

//  O(N + E)