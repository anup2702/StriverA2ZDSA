
class Solution {
public:

    TreeNode* fn(vector<int>& postorder, int postSt, int postEnd, vector<int>& inorder, int inSt, int inEnd, map<int, int>& mp){
            if(postSt > postEnd or inSt > inEnd) return NULL;
            TreeNode* root = new TreeNode(postorder[postEnd]);
            int inRoot = mp[root->val];
            int elLeft = inRoot - inSt;
            root->left = fn(postorder, postSt, postSt+elLeft-1, inorder, inSt, inRoot-1, mp);
            root->right = fn(postorder, postSt+elLeft, postEnd-1, inorder, inRoot+1, inEnd, mp);
            return root;
        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int> mp; // el, pos
        for(int i=0; i<n; i++) mp[inorder[i]] = i;
        TreeNode* root = fn(postorder, 0, n-1, inorder, 0, n-1, mp);
        return root;
    }
};