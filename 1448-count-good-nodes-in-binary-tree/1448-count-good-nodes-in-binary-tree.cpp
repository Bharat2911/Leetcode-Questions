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
    int count=0;
    
    void solve(TreeNode*root,int maxi)
    {
        if(root==NULL)return;
        
        //visitin all path
        
        if(root->val>=maxi)
        {
            count++;//we get the good node
            
            maxi=root->val;//update our maxi value
            
        }
        
        solve(root->left,maxi);
        solve(root->right,maxi);
        
    }
    int goodNodes(TreeNode* root) {
     
        //approach is super simple we just have to discover each path and keep the count og god nodes
        
        if(root==NULL)
        {
            return 0;
        }
        int maxi=root->val;
        
        solve(root,maxi);
        
        return count;
    }
};