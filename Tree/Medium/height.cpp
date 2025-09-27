int height(Node* root) {
    if (!root) return 0;  // empty tree has height 0
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

worst-case space complexity = O(n), best case (balanced) = O(log n).