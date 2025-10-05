class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* n = it.first;
            int line = it.second;
            if(mpp.find(line) == mpp.end()) mpp[line] = n->data;
            if(n->left) q.push({n->left, line-1});
            if(n->right) q.push({n->right, line+1});
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};