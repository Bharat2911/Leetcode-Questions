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
    
    TreeNode*solve(int lb,int ub,vector<int>&preorder,vector<int>&inorder)
    {
        if(lb>ub)
        {
            return NULL;
        }
        
        TreeNode*root=new TreeNode(preorder[idx]);
        
        idx++;
        
        int i=map[root->val];
        
        root->left=solve(lb,i-1,preorder,inorder);
        
        root->right=solve(i+1,ub,preorder,inorder);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int lb=0;
        int ub=inorder.size()-1;
        
        for(int i=0;i<inorder.size();i++)
        {
            map[inorder[i]]=i;
        }
        
        return solve(lb,ub,preorder,inorder);
        
    }
};