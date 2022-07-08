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
    void solve(TreeNode*root,int tsum,vector<vector<int>>&res,vector<int>&ans,int sum)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->val);
        
        if(root->left==NULL and root->right==NULL)//leaf node encounter
        {
            sum+=root->val;
            
            if(sum==tsum)
            {
                res.push_back(ans);
            }
            
        }
        sum+=root->val;
        
        solve(root->left,tsum,res,ans,sum);
        
        solve(root->right,tsum,res,ans,sum);
        
        //in the end just add a backtraking step
        
        ans.pop_back();//backtraking
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>res;
        
        vector<int>ans;
        
        if(root==NULL)
        {
            return res;
        }
        int sum=0;
        
        solve(root,targetSum,res,ans,sum);
        
        return res;
    }
};