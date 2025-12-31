class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<tuple<int,int,int>> cells;

        // store (height, r, c)
        for(int r = 0; r < n; r++)
            for(int c = 0; c < n; c++)
                cells.push_back({grid[r][c], r, c});

        sort(cells.begin(), cells.end());

        DisjointSet ds(n * n);
        vector<vector<bool>> active(n, vector<bool>(n, false));

        auto inside = [&](int r, int c){
            return r >= 0 && r < n && c >= 0 && c < n;
        };

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        for(auto &[h, r, c] : cells) {
            active[r][c] = true;
            int id1 = r * n + c;

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if(inside(nr, nc) && active[nr][nc]) {
                    int id2 = nr * n + nc;
                    ds.unite(id1, id2);
                }
            }

            // check connection
            if(ds.find(0) == ds.find(n*n - 1))
                return h;
        }

        return -1;
    }
};
