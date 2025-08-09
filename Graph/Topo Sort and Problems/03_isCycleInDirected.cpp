class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        vector<int> indegree(V, 0);  

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size() < V) return true;
        return false;
    }
};

/*
❗ Why ans.size() < V means there’s a cycle:
Let’s say:

V = 5 (total 5 nodes)
After processing, ans.size() = 3 (only 3 nodes processed)
That means 2 nodes were never processed — because they never reached indegree 0.
➡️ That can only happen if there’s a cycle.
⚠️ Why?
Because nodes in a cycle keep pointing to each other, and never reduce each other's indegree to 0 — they are "stuck".
Hence:
In an acyclic graph, all nodes are eventually added to ans, so ans.size() == V
In a cyclic graph, some nodes remain with indegree > 0 forever, so ans.size() < V


*/