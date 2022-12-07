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
    int ans=0;
    
    int height(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=0;
        int r=0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        //check that current value is equal to previous value 
        if(root->left and root->left->val==root->val)
        {
            l=left;
        }
        if(root->right and root->right->val==root->val)
        {
            r=right;
        }
        ans=max(ans,l+r);
        
        return max(l,r)+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        height(root);
        
        return ans;
    }
};