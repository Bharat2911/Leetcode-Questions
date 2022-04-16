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
    void solve(TreeNode*root,int &sum)
    {
        if(root==NULL)
        {
            return ;
        }
        
        // ..move right as in reverse inorder
        solve(root->right,sum);
        
        //update the root value as the sum of root->val +sum
        root->val=root->val+sum;
        
        //now update the sum as root->val 
        sum=root->val;
        
        //move to the left as in reverse inorder
        
        solve(root->left,sum);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        
        //if we observe that root value is added in the reverse inorder manner 
        
        //normal inorder left->root->right
        //reverse inorder right->root->left;
        
        
        int sum=0;
        solve(root,sum);
        
        return root;
    }
};