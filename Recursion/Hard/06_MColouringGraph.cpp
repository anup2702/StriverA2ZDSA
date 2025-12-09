class Solution {
  public:
    bool possible(int node, int col, vector<int>& color, vector<vector<int>>& graph, int v){
        for(int i=0; i<v; i++){
            if(i != node and graph[i][node]==1 and color[i] == col) return false;
        }
        return true;
    }
    bool solve(int node, vector<int>& color, int m, int v, vector<vector<int>>& graph){
        if(node==v) return true;
        for(int col=1; col<=m; col++){
            if(possible(node, col, color, graph, v)){
                color[node] = col;
                if(solve(node+1, color, m, v, graph)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColor(vector<vector<int>> graph, int v, int m){
        vector<int>color(v, 0);
        if(solve(0, color, m, v, graph)) return true;
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for(auto it: edges){
            graph[it[0]][it[1]] = 1;
            graph[it[1]][it[0]] = 1;
        }
        return graphColor(graph, v, m);
    }
};