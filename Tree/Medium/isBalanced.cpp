// Meaning: if either child is already unbalanced → whole tree is unbalanced.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = maxDepth(root->left);
        if(lh==-1) return -1;
        int rh = maxDepth(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+ max(lh,rh);
    }
};

// Time: O(n) Space: O(h)
// worst case = O(n), best case (balanced) = O(log n). - space