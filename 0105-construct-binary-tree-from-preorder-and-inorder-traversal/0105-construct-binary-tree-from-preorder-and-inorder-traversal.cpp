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
    
    TreeNode*solve(int lb,int ub,vector<int>&pre,vector<int>&inorder)
    {
        if(lb>ub)
        {
            return NULL;
        }
        
        TreeNode*root=new TreeNode(pre[idx]);
        
        int i=map[pre[idx]];
        
        idx++;
        root->left=solve(lb,i-1,pre,inorder);
        
        root->right=solve(i+1,ub,pre,inorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        
        for(int i=0;i<n;i++)
        {
            map[inorder[i]]=i;
        }
        
        int lb=0;
        int ub=n-1;
        
        return solve(lb,ub,preorder,inorder);
    }
};