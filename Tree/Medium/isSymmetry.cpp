class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || helper(root->left, root->right);
    }

    bool helper(TreeNode* left, TreeNode* right){

        if(!left || !right) return left==right;
        if(left->val != right->val) return false;

        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};