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
    unordered_map<int,int>map;
    int idx=0;
    
    TreeNode*solve(vector<int>&pre,vector<int>&in,int lb,int ub)
    {
        //base case
        if(lb>ub)return NULL;
        
       
        
        TreeNode* root=new TreeNode(pre[idx]);
        
        int i=map[pre[idx]];
        idx++;
        
        root->left=solve(pre,in,lb,i-1);
        
        root->right=solve(pre,in,i+1,ub);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=inorder.size();
        
        int lb=0;
        
        int ub=n-1;
        
        for(int i=0;i<n;i++)
        {
            map[inorder[i]]=i;
            
        }
        
        return solve(preorder,inorder,lb,ub);
    }
};