#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            rank.resize(n+1, 0);
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

        void unionByRank(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }
            else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            }
            else{
                parent[pv] = pu;
                rank[pu]++;
            }
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

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "Same Parent" << endl;
    }
    else{
        cout << "Different Parent" << endl;
    }
    return 0;
}


