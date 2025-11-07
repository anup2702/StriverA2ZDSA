
class Solution {
public:
    void findParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent, int start, TreeNode* &stNode) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            if(curr->val == start) stNode = curr;
            q.pop();
            if (curr->left) {
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if (curr->right) {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* stNode;
        findParent(root, parent, start, stNode);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(stNode);
        vis[stNode] = true;
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            time++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left and !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if (curr->right and !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if (parent[curr] and !vis[parent[curr]]) {
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
        }
        
        return time-1;
    }
};