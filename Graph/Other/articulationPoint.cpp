// User function Template for C++

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>& vis,
             vector<int> adj[], vector<int>& tin,
             vector<int>& low, vector<int>& mark) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, vis, adj, tin, low, mark);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] and parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 and parent == -1) mark[node] = 1;
    }

  public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        // Code here
        vector<int> vis(n, 0);
        vector<int> tin(n), low(n);
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, adj, tin, low, mark);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mark[i]) ans.push_back(i);
        }
        if(ans.empty()) ans.push_back(-1);
        
        return ans;
        
    }
};

// space- 3n
// v+e