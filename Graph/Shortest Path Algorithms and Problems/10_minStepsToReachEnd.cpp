// User function Template for C++

class Solution {
  public:
    
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        const int mod = 100000;
        vector<int> dist(mod, 1e9);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while(!q.empty()){
            int node = q.front(); q.pop();
            if(node==end) return dist[node];
            for(auto &x: arr){
                int next = (1LL*node*x)%mod;
                if(dist[node]+1 < dist[next]){
                    dist[next] = dist[node]+1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
