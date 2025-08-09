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

        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        st.insert({0, src});

        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for(auto &adj : adjList[node]) {
                int adjNode = adj.first;
                int edgeWt = adj.second;

                if(dis + edgeWt < dist[adjNode]) {
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgeWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};