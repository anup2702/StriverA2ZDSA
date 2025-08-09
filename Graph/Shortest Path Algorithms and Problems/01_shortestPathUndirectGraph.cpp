class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> dist(V, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int k = q.front();
            q.pop();

            for(auto it : adj[k]){
                if(dist[it] == -1){
                    dist[it] = dist[k] + 1;
                    q.push(it);
                }
            }
        }

        return dist;
    }
};
