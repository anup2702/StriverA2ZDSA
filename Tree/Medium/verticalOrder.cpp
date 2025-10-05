class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int, vector<pair<int, int>>> mpp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while(!q.empty()){
            auto [n, col, row] = q.front();
            q.pop();
            mpp[col].push_back({n->val, row});
            if(n->left) q.push({n->left, col-1, row+1});
            if(n->right) q.push({n->right, col+1, row+1});
        }
        
        for(const auto& it: mpp){
            const vector<pair<int, int>>& colNodes = it.second;
            vector<pair<int, int>> sorted = colNodes;
            sort(sorted.begin(), sorted.end(), comp); 
            vector<int> currentRow;
            for(const auto &p : sorted){
                currentRow.push_back(p.first);
            }
            ans.push_back(currentRow);
        }
        return ans;
    }
};