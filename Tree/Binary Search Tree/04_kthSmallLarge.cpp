// Inorder Traversal

// Kth smallest is Kth element of inorder traversal
// Kth largest is (n -k)th element of inorder traversal

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1, cnt = 0;
        inorder(root, k, cnt, res);
        return res;
    }

    void inorder(TreeNode* root, int k, int& cnt, int& res){
        if(!root) return;
        inorder(root->left, k, cnt, res);
        cnt++;
        if(cnt == k){
            res = root->val;
            return;
        }
        inorder(root->right, k, cnt, res);
    }
};