/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int i = 0;
    unordered_map<int, int> map;

    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int lb, int ub)
    {
        if (lb > ub) return NULL;

        int index = map[preorder[i]];

        TreeNode *root = new TreeNode(preorder[i]);
        i++;

        root->left = solve(preorder, inorder, lb, index - 1);
        root->right = solve(preorder, inorder, index + 1, ub);

        return root;
    }
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {

       	//ele of inorder with therie index

        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        int lb = 0;
        int ub = inorder.size() - 1;

        return solve(preorder, inorder, lb, ub);
    }
};