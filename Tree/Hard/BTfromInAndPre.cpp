class Solution {
public:
    TreeNode* fn(vector<int>& preorder, int preSt, int preEnd, vector<int>& inorder, int inSt, int inEnd, map<int, int>& mp){
        if(preSt > preEnd or inSt > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preSt]);
        int inRoot = mp[root->val];
        int elLeft = inRoot - inSt;
        root->left = fn(preorder, preSt+1, preSt+elLeft, inorder, inSt, inRoot-1, mp);
        root->right = fn(preorder, preSt+elLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int,int> mp; // el, pos
        for(int i=0; i<n; i++) mp[inorder[i]] = i;
        TreeNode* root = fn(preorder, 0, n-1, inorder, 0, n-1, mp);
        return root;
    }
};