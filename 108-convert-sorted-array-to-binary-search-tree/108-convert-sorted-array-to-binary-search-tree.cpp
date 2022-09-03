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
    TreeNode*solve(vector<int>&nums,int lb,int ub)
    {
        if(lb>ub)return NULL;
        
        int idx=(lb+ub)/2;
        
        TreeNode*root=new TreeNode(nums[idx]);
        
        root->left=solve(nums,lb,idx-1);
        
        root->right=solve(nums,idx+1,ub);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size();
        
        int lb=0;
        int ub=n-1;
        
        return solve(nums,lb,ub);
    }
};