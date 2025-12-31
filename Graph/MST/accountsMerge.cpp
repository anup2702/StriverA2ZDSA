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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailNode.find(mail)==mailNode.end()) mailNode[mail] = i; // first time
                else ds.unionBySize(i, mailNode[mail]); // if seen  
            }
        }
        vector<vector<string>> merged(n);
        for(auto it: mailNode){
            string mail = it.first;
            int node = ds.findParent(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> result;
        for(int i=0; i<n; i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: merged[i]){
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};





















