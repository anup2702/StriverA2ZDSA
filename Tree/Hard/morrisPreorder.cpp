#include <iostream>
#include <vector>
using namespace std; 

// Node Structure
class Node { 
public:
    int data; 
    Node *left, *right; 
	Node(int x){
      	data = x;
      	left = right = nullptr;
    }
}; 

vector<int> preOrder(Node* root) {
    vector<int> res;
    while (root) {
        
        // If left child is null, store the current node
        // data and move to right child
        if (root->left == nullptr) {
            res.push_back(root->data);
            root = root->right;
        }
        else {
            
            // Find inorder predecessor
            Node* current = root->left;
            while (current->right && current->right != root)
                current = current->right;

            // If the right child of inorder predecessor
            // already points to this node
            if (current->right == root) {
                current->right = nullptr;
                root = root->right;
            }
            
            // If right child doesn't point to this node
            else {
                res.push_back(root->data);  
                current->right = root;
                root = root->left;
            }
        }
    }
    return res;
}
 

int main()  { 
  
    // Constructing binary tree. 
    //             1
    //            / \
    //           2   3
    //          / \ 
    //         4  5 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = preOrder(root);
  
     for (int data : res) {
        cout << data << " ";
    }
  
    return 0; 
}