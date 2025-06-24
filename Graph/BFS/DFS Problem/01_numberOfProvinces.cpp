class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjList){
        vis[node] = 1;
        for(auto it : adjList[node]) {
            if(!vis[it]) {
                dfs(it, vis, adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjList(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i); 
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adjList);
                cnt++;
            }
        }

        return cnt;
    }
};
