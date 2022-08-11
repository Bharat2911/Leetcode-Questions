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
    bool solve(TreeNode*root,long long int mini,long long int maxi)
    {
        if(root==NULL)return true;
        
        if(root->val<=mini || root->val >=maxi)
        {
            return false;
        }
        // if(root->val>mini and root->val<maxi)
        // {
        //     return true;
        // }
        
        return solve(root->left,mini,root->val) and solve(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL)return true;
        
       long long int mini=-1e18;
        long long int maxi=1e18;
        
       
        return solve(root,mini,maxi);
    }
};