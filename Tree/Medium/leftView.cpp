class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=1; i<=size; i++){
                TreeNode* n = q.front();
                if(i == size){
                    ans.push_back(n->val);
                }
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);  
                q.pop();
            }
        }
        return ans;
    }
};