class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj[V];
    	for (auto it : edges) {
    		vector<int> tmp(2);
    		tmp[0] = it[1];
    		tmp[1] = it[2];
    		adj[it[0]].push_back(tmp);
    
    		tmp[0] = it[0];
    		tmp[1] = it[2];
    		adj[it[1]].push_back(tmp);
    	}
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node]){
                int edgeWt = it[1];
                int adjnode = it[0];
                if(!vis[adjnode]){
                    pq.push({edgeWt, adjnode});
                }
            }
        }
        return sum;
    }
};