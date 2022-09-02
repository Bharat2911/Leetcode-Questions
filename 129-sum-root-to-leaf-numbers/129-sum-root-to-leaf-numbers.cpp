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

        void solve(TreeNode *root, int &sum,int num)
        {
            if (root == NULL)
            {
                return ;
            }

            

            num = num *10 + (root->val );

            if (root->left == NULL and root->right == NULL)
            {
                sum+=num;
            }
            
            solve(root->left,sum,num);
            solve(root->right,sum,num);

        }
    int sumNumbers(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        int sum = 0;
        int num=0;
        
        solve(root, sum,num);

        return sum;
    }
};