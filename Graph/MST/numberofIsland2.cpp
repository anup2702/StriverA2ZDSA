class DisjointSet {
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }

        }
};


vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    // Write your code here.
    vector<int> ans;
    DisjointSet ds(n*m);
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int dr[] = {-1, +1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for(auto it: queries){
        int r = it[0], c = it[1];
        if(vis[r][c]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[r][c] = 1;
        cnt++;
        for(int i=0; i<4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr>=0 and nc>=0 and nr<n and nc<m and vis[nr][nc]==1){
                int node = r*m+c, adjNode = nr*m+nc;
                if(ds.findParent(node) != ds.findParent(adjNode)){
                    cnt--;
                    ds.unionBySize(node, adjNode);
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}
