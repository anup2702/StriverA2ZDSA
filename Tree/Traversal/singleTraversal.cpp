class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {

        vector<vector<int>> traversal(3); // 0: pre, 1: in, 2: post
        if (root == NULL) return traversal;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto &top = st.top();
            TreeNode* node = top.first;
            int state = top.second;

            if (state == 1) {
                traversal[0].push_back(node->data);
                top.second++;
                if (node->left)
                    st.push({node->left, 1});
            }
            else if (state == 2) {
                traversal[1].push_back(node->data);
                top.second++;
                if (node->right)
                    st.push({node->right, 1});
            }
            else {
                traversal[2].push_back(node->data);
                st.pop();
            }
        }

        return traversal;
    }
};
