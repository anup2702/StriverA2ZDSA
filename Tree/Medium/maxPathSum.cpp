class Solution {
public:
    int maxPath(TreeNode* root, int &maxi){
        if(!root) return 0;
        int leftSum = max(0,maxPath(root->left, maxi));
        int rightSum = max(0,maxPath(root->right, maxi));
        maxi = max(maxi, root->val+leftSum+rightSum);
        return (root->val + max(leftSum, rightSum));
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi; 
    }
};