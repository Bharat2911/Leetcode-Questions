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
    TreeNode*tree=new TreeNode(-1);
    TreeNode*ptr=tree;
    
    void solve(TreeNode*root)
    {
        if(root==NULL)return;
        
        //inorder traversal left->root->right;
        
        solve(root->left);
        
        ptr->right=new TreeNode(root->val);
        
        
        ptr=ptr->right;
        
        solve(root->right);
        
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        //we have to move to the left so will doing inorder traversal
        solve(root);
        
        return tree->right;
    }
};