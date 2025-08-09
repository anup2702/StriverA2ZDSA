// dfs but pushing in a stack
class Solution {
  public:
  
  void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>>& adjList) {
      vis[node] = 1;
      for(auto it: adjList[node]) {
          if(!vis[it]) dfs(it, vis, st, adjList); 
      }
      st.push(node);
  }

  vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        vector<int> vis(V, 0);  
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, vis, st, adjList);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};



