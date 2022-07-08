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
        bool f = false;
    void solve(TreeNode *root, int tsum, int sum)
    {
        if (root == NULL)
        {
            return ;
        }

        if (root->left == NULL and root->right == NULL)
        {
            sum += root->val;

            if (sum == tsum)
            {
                f = true;
            }
        }
        
        sum+=root->val;
        
        solve(root->left,tsum,sum);
        
        solve(root->right,tsum,sum);
        
    }
    bool hasPathSum(TreeNode *root, int tsum)
    {

        if (root == NULL)
        {
            return false;
        }
       int sum=0;
        
        solve(root, tsum,sum);

        return f;
    }
};