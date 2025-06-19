// Inorder traversal of a Binary Search Tree (BST) should yield a sorted sequence of unique values.

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i+1] <= arr[i]) return false;
        }
        return true;
    }
};

// Search 

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
           while(root){
                if(root->val == val) return root;
                else if(root->val < val) root = root->right;
                else root = root->left;
           }
           return root;
    }
};


// Min Max
class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        while(root->left){
            root = root->left;
        }
        return root->data;
    }
};

    int maxValue(Node* root) {
        // Code here
        while(root->right){
            root = root->right;
        }
        return root->data;
    }
};