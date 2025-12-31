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

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                for(int idx = 0; idx<4; idx++){
                    int nr = i + dr[idx], nc = j + dc[idx];
                    if(nr>=0 and nc>=0 and nr<n and nc<n and grid[nr][nc]==1){
                        int node = i*n+j, adjNode = nr*n+nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxSize = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                set<int> components;
                for(int idx = 0; idx<4; idx++){
                    int nr = i + dr[idx], nc = j + dc[idx];
                    if(nr>=0 and nc>=0 and nr<n and nc<n and grid[nr][nc]==1){
                        components.insert(ds.findParent(nr*n + nc));
                    }
                }
                int totalSize = 0;
                for(auto it: components){
                    totalSize += ds.size[it];
                }
                maxSize = max(maxSize, totalSize+1);
            }
        }

        for(int i=0; i<n*n; i++){
            maxSize = max(maxSize, ds.size[ds.findParent(i)]);
        }
        return maxSize;
    }
};