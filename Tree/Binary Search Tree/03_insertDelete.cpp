class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *temp = new TreeNode(val);
        if (!root)
            return temp;
        TreeNode *curr = root;
        while (true)
        {
            if (curr->val < val)
            {
                if (curr->right)
                {
                    curr = curr->right;
                }
                else
                {
                    curr->right = temp;
                    break;
                }
            }
            else
            {
                if (curr->left)
                {
                    curr = curr->left;
                }
                else
                {
                    curr->left = temp;
                    break;
                }
            }
        }
        return root;
    }
};

// Deletion

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    TreeNode *helper(TreeNode *root)
    {
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLR(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode *findLR(TreeNode *root)
    {
        if (!root->right)
            return root;
        return findLR(root->right);
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (root->val == key)
            return helper(root);

        TreeNode *dummy = root;
        while (root)
        {
            if (root->val > key)
            {
                if (root->left and root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            else
            {
                if (root->right and root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }
        return dummy;
    }
};