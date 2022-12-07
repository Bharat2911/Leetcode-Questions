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
        void solve(TreeNode *root, vector<int> &inorder)
        {
            if (root == NULL)
            {
                return;
            }
            solve(root->left, inorder);

            inorder.push_back(root->val);

            solve(root->right, inorder);
        }
    int rangeSumBST(TreeNode *root, int low, int high)
    {

       	//approach 1->T.C=O(h) S.C=O(h)
        vector<int> inorder;

        if (root == NULL)
        {
            return 0;
        }

        solve(root, inorder);
        int ans = 0;

        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] >= low and inorder[i] <= high)
            {
                ans += inorder[i];
            }
        }
        return ans;
    }
};