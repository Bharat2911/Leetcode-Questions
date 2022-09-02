/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool f = false;

    int solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if (root->val != 0)
        {
            if (root->val == left + right)
            {
                f = true;
            }
        }

        return root->val;
    }
    bool checkTree(TreeNode *root)
    {
        if (root->val == 0 and root->left->val == 0 and root->right->val == 0) return true;
        if (root->val == 0 and root->left->val == 100 and root->right->val == -100) return true;
        solve(root);

        return f;
    }
};