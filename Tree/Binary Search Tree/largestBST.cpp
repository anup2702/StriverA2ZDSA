class Solution {
  public:
    bool isValid(Node* root, int mini, int maxi){
        if(!root) return true;
        if(root->data >= maxi or root->data <=mini) return false;
        return isValid(root->left, mini, root->data) and isValid(root->right, root->data, maxi);
    }
    int size(Node* root){
        if(!root) return 0;
        return 1+size(root->left)+size(root->right);
    }
    int largestBst(Node *root) {
        if(!root) return 0;
        if(isValid(root, INT_MIN, INT_MAX)) return size(root);
        return max(largestBst(root->left), largestBst(root->right));
    }
}; 
// n^2

class Solution {
public:
    struct BSTInfo {
        int mini;
        int maxi;
        int size;

        BSTInfo(int mn, int mx, int sz) {
            mini = mn;
            maxi = mx;
            size = sz;
        }
    };

    BSTInfo largestBSTBT(Node* root) {
        if (!root) {
            return BSTInfo(INT_MAX, INT_MIN, 0);
        }

        BSTInfo left = largestBSTBT(root->left);
        BSTInfo right = largestBSTBT(root->right);

        if (left.maxi < root->data && root->data < right.mini) {
            return BSTInfo(
                min(left.mini, root->data),
                max(right.maxi, root->data),
                1 + left.size + right.size
            );
        }

        return BSTInfo(
            INT_MIN,
            INT_MAX,
            max(left.size, right.size)
        );
    }

    int largestBst(Node* root) {
        return largestBSTBT(root).size;
    }
};
// o(n)