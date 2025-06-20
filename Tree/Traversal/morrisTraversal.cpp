
vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){ // No left
            inorder.push_back(curr->val);
            curr = curr->right;
        } else{
            TreeNode* prev = curr->left;
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }
            if(!prev->right){ // rightmost node of left 
                prev->right = curr; // create thread
                curr = curr->left;
            } else{
                prev->right = NULL; // cut thread
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

// O(n) - time, O(1) - space 

vector<int> getPreorder(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){ // No left
            preorder.push_back(curr->val);
            curr = curr->right;
        } else{
            TreeNode* prev = curr->left;
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }
            if(!prev->right){
                prev->right = curr; // create thread
                preorder.push_back(curr->val);
                curr = curr->left;
            } else{
                prev->right = NULL; // cut thread
                curr = curr->right;
            }
        }
    }
    return preorder;
}