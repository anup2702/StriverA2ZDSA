
using ll = long long;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        const long long INF = 1e18;
        vector<vector<pair<int, ll>>> adjList(n);
        for(auto it: roads){
            adjList[it[0]].push_back({it[1], (ll)it[2]});
            adjList[it[1]].push_back({it[0], (ll)it[2]});
        }

        priority_queue<pair<ll ,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        vector<ll> dist(n, INF);
        vector<ll> ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0}); // dist, node


        while(!pq.empty()) {
            ll dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it : adjList[node]) {
                int adjNode = it.first;
                ll edgeWt = it.second;

                ll newDist = edgeWt + dis;

                if(newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(newDist == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};