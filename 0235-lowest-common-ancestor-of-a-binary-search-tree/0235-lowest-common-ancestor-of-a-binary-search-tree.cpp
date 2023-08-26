/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //brute force dono node tak ka path store kar lo then 
    //dono ke path mai jo last same elemnt hoga vo apna answer hai 
    TreeNode*solve(TreeNode*root,TreeNode*p,TreeNode*q)
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        if(root==p || root==q)
        {
            return root;
        }
        
        TreeNode*left=solve(root->left,p,q);
        TreeNode*right=solve(root->right,p,q);
        
        if(!left)return right;
        else if(!right)return left;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
        {
            return NULL;
        }
        
        return solve(root,p,q);
    }
};