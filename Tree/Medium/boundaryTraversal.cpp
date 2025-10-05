/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    
    bool isLeaf(Node* node){
        return (!node->left and !node->right);
    }
    
    void leftBoundary(Node* root, vector<int>& res){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void leafNode(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) leafNode(root->left, res);
        if(root->right) leafNode(root->right, res);
    }
    
    void rightBoundary(Node* root, vector<int> &res){
        Node* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i= temp.size()-1; i>=0; i--){
            res.push_back(temp[i]);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        leftBoundary(root, res);
        leafNode(root, res);
        rightBoundary(root, res);
        return res;
    }
};