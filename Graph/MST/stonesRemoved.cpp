class DisjointSet {
    vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0; i <= n; i++){
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int r = 0, c = 0;
        for(auto st: stones){
            r = max(r, st[0]);
            c = max(c, st[1]);
        }
        DisjointSet ds(r+c+1);
        unordered_map<int, int> stone;
        for(auto it: stones){
            int nR = it[0];
            int nC = it[1]+r+1;
            ds.unionBySize(nR, nC);
            stone[nR] = 1; stone[nC] = 1;
        }
        int cnt = 0;
        for(auto it: stone){
            if(ds.findParent(it.first)==it.first) cnt++;
        }
        return n-cnt;
    }
};