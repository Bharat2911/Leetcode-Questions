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
    void solve(TreeNode*root,int ts,long long sum)
    {
        if(root==NULL)
        {
            return;
        }
        
        
        
        sum+=root->val;
        
        if(sum==ts)count++;
        
        solve(root->left,ts,sum);
        solve(root->right,ts,sum);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
        {
            return 0;
            
        }
        long long sum=0;
        
        solve(root,targetSum,sum);
        
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return count;
    }
};