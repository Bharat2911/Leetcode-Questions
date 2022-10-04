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
    void solve(TreeNode*root,unordered_map<int,int>&map,int sum)
    {
        if(root==NULL)
        {
            return;
        }
        
        sum+=root->val;
        
        if(root->left==NULL and root->right==NULL)
        {
            //means we encounter the leaf node
            map[sum]++;
        }
        
        solve(root->left,map,sum);
        solve(root->right,map,sum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)return false;
        
        unordered_map<int,int>map;
        
        int sum=0;
        
        solve(root,map,sum);
        
        if(map.find(targetSum)!=map.end())
        {
            return true;
        }
        return false;
        
    }
};