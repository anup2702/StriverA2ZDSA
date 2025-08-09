class Solution {
public:
vector<int>ans;

void preorder(TreeNode* root){
    if(root){
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return(ans);
    }
};


vector<int> ans;
void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
}
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return(ans);
    }
};


vector<int> ans;
void postorder(TreeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);

    }
}
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return(ans);
    }
};