// User Function Template
// No negative distance , no neg cycle --> infintie loop
// TC - O(ElogV)
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adjList(V);
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, 1e9);
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adjList[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if(dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
