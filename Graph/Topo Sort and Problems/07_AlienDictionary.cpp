class Solution {
public:

    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        vector<int> indegree(V, 0);

        for(int u = 0; u < V; u++){
            for(int v : adj[u])
                indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++)
            if(indegree[i] == 0) q.push(i);

        vector<int> ans;

        while(!q.empty()){
            int node = q.front(); 
            q.pop();
            ans.push_back(node);

            for(int nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        return ans;
    }

    string findOrder(vector<string> &words) {

        vector<vector<int>> adj(26);

        for(int i = 0; i + 1 < words.size(); i++){
            string &s1 = words[i];
            string &s2 = words[i+1];

            // invalid prefix (abcd , abc)
            if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2)
                return "";

            for(int j = 0; j < min(s1.size(), s2.size()); j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(26, adj);

        string order = "";
        for(int x : topo)
            order += char('a' + x);

        return order;
    }
};
