class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int k = q.size();
            long long first = q.front().second, last = q.back().second;
            ans = max(ans, last - first + 1);
            for(int i=0; i<k; i++){
                auto [node, idx] = q.front();
                idx -= first;
                q.pop();
                if(node->left) q.push({node->left, 2*idx+1});
                if(node->right) q.push({node->right, 2*idx+2});
            }
        }
        return int(ans);
    }
};