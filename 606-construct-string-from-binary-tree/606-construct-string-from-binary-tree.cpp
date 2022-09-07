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
    void solve(TreeNode*root,string &str)
    {
        if(root==NULL)return;
        
        str+=to_string(root->val);
        
        if(root->left!=NULL)
        {
            str+="(";
            
            solve(root->left,str);
            
            str+=")";
        }
        
        if(root->right!=NULL)
        {
            if(root->left==NULL)
            {
                str+="()";
            }
            str+="(";
            
            solve(root->right,str);
            
            str+=")";
            
        }
    }
    string tree2str(TreeNode* root) {
        
        string str;
        
        if(root==NULL)
        {
            return str;
        }
        
        solve(root,str);
        
        return str;
    }
};