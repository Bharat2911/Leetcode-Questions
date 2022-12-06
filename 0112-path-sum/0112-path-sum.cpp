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
    bool ans=false;
    
    void solve(TreeNode*root,int target,int sum)
    {
        if(root==NULL)return ;
        
        sum+=root->val;
        
        //base case
        if(root->left==NULL and root->right==NULL)
        {
            if(sum==target)
            {
                ans=true;
            }
        }
        solve(root->left,target,sum);
        solve(root->right,target,sum);
    }
    bool hasPathSum(TreeNode* root, int target) {
        
        if(root==NULL)
        {
            return false;
        }
        
        int sum=0;
        
        solve(root,target,sum);
        
        return ans;
    }
};