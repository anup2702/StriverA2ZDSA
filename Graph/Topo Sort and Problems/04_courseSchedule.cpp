class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjList(V);
        vector<int> indegree(V, 0);  

        for(auto& edge : prerequisites){
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
        
        if(ans.size() == V) return true;
        return false;
    }
};