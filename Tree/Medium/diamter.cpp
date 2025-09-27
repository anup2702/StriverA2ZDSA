class Solution {
public:
    int diameterUtil(TreeNode* root, int& dia){
        if(!root) return 0;
        int left = diameterUtil(root->left, dia);
        int right = diameterUtil(root->right, dia);
        dia = max(dia, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameterUtil(root, dia);
        return dia;
    }
};

time - O(n) space - O(h)