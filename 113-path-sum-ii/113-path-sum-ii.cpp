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
        void solve(TreeNode *root, vector<vector < int>> &ans, vector< int > res,int sum,int targetSum)
        {
            if (root == NULL) return;
            
             res.push_back(root->val);
            
             sum+=root->val;
            
            if (root->left == NULL and root->right == NULL)
            {
               if(sum==targetSum)
               {
                   ans.push_back(res);
               }
                else
                {
                    sum=0;
                }
            }
            
            solve(root->left, ans, res,sum,targetSum);

            solve(root->right, ans, res,sum,targetSum);
        }
    vector<vector < int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector < int>> res;

        vector<int> ans;

        int sum = 0;

        solve(root, res, ans,sum,targetSum);

       return res;
        
    }
};