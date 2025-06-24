class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(auto edge: edges){
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first);
        }
        return adjList;
    }
};