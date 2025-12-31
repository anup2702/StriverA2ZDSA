// User function Template for C++

class DisjointSet {
    vector<int> parent, size;
    public:
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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        sort(edges.begin(), edges.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[2] < b[2]; 
         });
            
        DisjointSet ds(V);
        int mstWt = 0;
        for(auto it: edges){
            int wt = it[2];
            int u = it[0], v = it[1];
            if(ds.findParent(u) != ds.findParent(v)){
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
        
    }
};