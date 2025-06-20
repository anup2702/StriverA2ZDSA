 // Maintain range

 
 #define ll long long
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST(TreeNode* root, ll minVal, ll maxVal){
        if(!root) return true;
        // if goes out of range, return false
        if(root->val >= maxVal || root->val <= minVal) return false;
        // goes left update maxVal, goes right update minVal
        return isValidBST(root->left, minVal, root->val) &&
            isValidBST(root->right, root->val, maxVal);
    }
};