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
    //using the fact that inorder of binary search tree is always sorted
    bool issorted(vector<int>&nums)
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    void solve(TreeNode*root,vector<int>&in)
    {
        if(root==NULL)return ;
        
        solve(root->left,in);
        
        in.push_back(root->val);
        
        solve(root->right,in);
    }
    bool isValidBST(TreeNode* root) {
        
        vector<int>in;
        
        solve(root,in);
        
        return issorted(in);
    }
};