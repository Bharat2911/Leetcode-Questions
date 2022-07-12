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
    // we have to space optimised it bro
    
    int ans=0;
    int count=0;
    
    void solve(TreeNode*root,int k)
    {
        if(root==NULL)return;
        
        //inorder
        solve(root->left,k);
        
        count++;
        
        if(count==k)ans=root->val;
        
        solve(root->right,k);
            
            
    }
    int kthSmallest(TreeNode* root, int k) {
        
        
        
        if(root==NULL)return 0;
        
        solve(root,k);
        
        return ans;
    }
};