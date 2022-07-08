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
        int count = 0;
    void solve(TreeNode *root, int tsum, long long sum)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->val;

        if (sum == tsum)
        {
            count++;
        }

        solve(root->left, tsum, sum);
        solve(root->right, tsum, sum);
    }
    int pathSum(TreeNode *root, int targetSum)
    {

       	//in this we have to do a preorder traversal 
       	//so after traversing each node i will be checking the sum
        if (root == NULL)
        {
            return 0;
        }
        long long sum = 0;

        solve(root, targetSum, sum);

       	//send the same function to left and right so each and every node will be checked

        pathSum(root->left, targetSum);

        pathSum(root->right, targetSum);

        return count;
    }
};