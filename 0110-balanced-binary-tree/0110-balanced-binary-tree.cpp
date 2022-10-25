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
class Solution {
public:
    bool f=true;
    int solve(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        
        if(abs(left-right)>1)
        {
            f=false;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL)
        {
            return true;
            
        }
        solve(root);
        
        return f;
    }
};