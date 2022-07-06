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
    void solve(TreeNode*root,int low,int high,int &sum)
    {
        //i will follow the preorder traversal here
        
        if(root==NULL)
        {
            return;
        }
           
        // root->left->right 
        
        if(root->val>=low and root->val<=high)
        {
            sum+=root->val;
        }
        
        solve(root->left,low,high,sum);
        
        solve(root->right,low,high,sum);
        
        
        
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        //write a recursive function for this then
        
        //base case
        if(root==NULL)
        {
            return 0;
        }
        int sum=0;
        
        solve(root,low,high,sum);
        
        return sum;
        
    }
};