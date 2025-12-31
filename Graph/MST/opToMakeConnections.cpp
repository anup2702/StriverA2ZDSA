class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int extra = 0, components = n;
        for (auto it : connections)
        {
            int u = it[0], v = it[1];
            if (ds.findParent(u) != ds.findParent(v))
            {
                ds.unionBySize(u, v);
                components--;
            }
            else
                extra++;
        }
        int needed = components - 1;
        return (extra >= needed) ? needed : -1;
    }
};