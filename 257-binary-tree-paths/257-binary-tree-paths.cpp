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
    void solve(TreeNode*root,vector<string>&ans,string res)
    {
        if(root==NULL)return;
        
        if(root->left==NULL and root->right==NULL)
        {
            res+=to_string(root->val);
            
            ans.push_back(res);
            
            return;
            
        }
        
        res+=to_string(root->val)+"->";
        
        solve(root->left,ans,res);
        solve(root->right,ans,res);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        string res="";
        
        solve(root,ans,res);
        
        return ans;
        
    }
};