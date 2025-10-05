class Solution {
public:
    bool isLeaf(Node* node) {
        return (!node->left && !node->right);
    }

    bool isSumProperty(Node *root) {
        if (!root || isLeaf(root)) return true;

        int leftData = 0, rightData = 0;
        if (root->left)  leftData = root->left->data;
        if (root->right) rightData = root->right->data;

        bool current = (root->data == leftData + rightData);
        bool leftOK = isSumProperty(root->left);
        bool rightOK = isSumProperty(root->right);

        return current && leftOK && rightOK;
    }
};
