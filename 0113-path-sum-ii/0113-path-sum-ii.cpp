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
    
    void solve(TreeNode*root,vector<vector<int>>&ans,vector<int>path,int target,int sum)
    {
        if(root==NULL)
        {
            return;
        }
        sum+=root->val;
        path.push_back(root->val);
        
        if(root->left==NULL and root->right==NULL)
        {
            if(sum==target)
            {
                ans.push_back(path);
                return;
            }
        }
        solve(root->left,ans,path,target,sum);
        solve(root->right,ans,path,target,sum);
        
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<vector<int>>ans;
        vector<int>path;
        
        if(root==NULL)
        {
            return ans;
        }
        
        int sum=0;
        
        solve(root,ans,path,target,sum);
        
        return ans;
        
    }
};