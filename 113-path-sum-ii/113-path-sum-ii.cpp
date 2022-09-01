/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void solve(TreeNode *root, vector<vector < int>> &ans, vector< int > res)
        {
            if (root == NULL) return;

            if (root->left == NULL and root->right == NULL)
            {
                res.push_back(root->val);

                ans.push_back(res);

                return;
            }
            res.push_back(root->val);

            solve(root->left, ans, res);

            solve(root->right, ans, res);
        }
    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector < int>> res;

        vector<int> ans;

        int sum = 0;

        solve(root, res, ans);

        vector<vector < int>> v;

        for (auto itr: res)
        {
            int sum = 0;

            for (auto x: itr)
            {
                sum += x;
            }
            if (sum == targetSum)
            {
                v.push_back(itr);
            }
        }
        return v;
    }
};