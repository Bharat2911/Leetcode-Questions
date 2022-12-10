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
    long long mod=1e9+7;
    
    void solve(TreeNode*root,long long int &sum)
    {
        if(root==NULL)
        {
            return ;
        }
        sum+=root->val;
        
        solve(root->left,sum);
        solve(root->right,sum);
        
    }
    int f(TreeNode*root,long long int &sum,long long int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left=f(root->left,sum,ans);
        int right=f(root->right,sum,ans);
        
        ans=max({ans,(sum-left)*left,(sum-right)*right});
                
        return left+right+root->val;
    }
    
    int maxProduct(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        long long int total_sum=0;
        
        solve(root,total_sum);
        
        long long int ans=INT_MIN;
        
        f(root,total_sum,ans);
        
        return ans%mod;
    }
};