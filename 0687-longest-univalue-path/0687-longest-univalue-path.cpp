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
    int solve(TreeNode*root,int prev,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left=solve(root->left,root->val,ans);
        
        int right=solve(root->right,root->val,ans);
        
        ans=max(left+right,ans);
        
        if(root->val==prev)
        {
            return max(left+1,right+1);
        }
        else 
        {
            return 0;
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        
        //appraoach ->maintain the previous variable man
        if(root==NULL)
        {
            return 0;
        }
        
        int previous=root->val;
        int ans=0;
        
        solve(root,previous,ans);
        
        return ans;
    }
};