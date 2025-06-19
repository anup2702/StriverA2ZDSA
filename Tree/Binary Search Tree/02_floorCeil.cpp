// Finding ceil 
// val >= key

int findCeil(Node* root, int input) {
    int ceil = -1;
    
    while(root){
        if(root->data == input){
            ceil = root->data;
            return ceil;
        }
        else if(root->data < input){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// Finding floor
// val <= key

// Function to search a node in BST.
class Solution{
public:
    int floor(Node* root, int x) {
        int flr = -1; 
        while(root){
            if(root->data == x){
                flr = root->data;
                return flr;
            }
            else if(root->data < x){
                flr = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }  
        return flr; 
    }
};
        