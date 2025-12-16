class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        function<void(TreeNode*)> inorder = [&](TreeNode* curr){
            if(!curr) return;
            inorder(curr->left);
            if(prev and prev->val > curr->val){
                if(!first) first = prev;
                second = curr;
            }
            prev = curr;
            inorder(curr->right);
        };
        inorder(root);
        swap(first->val, second->val);
    }
};