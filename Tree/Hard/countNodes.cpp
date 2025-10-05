class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = findHeightL(root);
        int rh = findHeightR(root);
        if (lh == rh)
            return (1 << lh) - 1; // 2^height - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findHeightL(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->left;
        }
        return height;
    }

    int findHeightR(TreeNode *node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->right;
        }
        return height;
    }
};