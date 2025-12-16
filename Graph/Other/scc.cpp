//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs1(int node, vector<vector<int>> &adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs1(it, adj, vis, st);
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<vector<int>> &revAdj, vector<int>& vis){
        vis[node] = 1;
        for(auto it: revAdj[node]){
            if(!vis[it]) dfs2(it, revAdj, vis);
        }
    }
   
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        stack<int> st;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs1(i, adj, vis, st);
        }
        
        vector<vector<int>> revAdj(n);
        for(int u=0; u<n; u++){
            for(int v: adj[u]){
                revAdj[v].push_back(u);
            }
        }
        fill(vis.begin(), vis.end(), 0);
        int cnt = 0;
        while(!st.empty()){
            int node = st.top(); st.pop();
            if(!vis[node]){
                dfs2(node, revAdj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};