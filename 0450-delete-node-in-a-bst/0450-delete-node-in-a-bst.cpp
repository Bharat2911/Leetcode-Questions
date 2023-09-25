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
    
    TreeNode* solve(int lb,int ub,vector<int>&p,vector<int>&inorder)
    {
        if(lb>ub)
        {
            return NULL;
        }
        
        TreeNode*root=new TreeNode(p[idx]);
        
        idx++;
        
        int i=map[root->val];
        
        
        root->left=solve(lb,i-1,p,inorder);
        
        root->right=solve(i+1,ub,p,inorder);
        
        return root;
    }
    
    void preorder(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        ans.push_back(root->val);
        
        preorder(root->left,ans);
        
        preorder(root->right,ans);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        vector<int>pre;
        
        preorder(root,pre);
        
        
        vector<int>p;
        
        for(auto itr:pre)
        {
            if(itr!=key)
            {
                p.push_back(itr);
            }
        }
        
        vector<int>inorder=p;
        
        int n=p.size();
        int lb=0;
        
        int ub=n-1;
        sort(inorder.begin(),inorder.end());
        
        for(int i=0;i<n;i++)
        {
            map[inorder[i]]=i;
        }
        
        return solve(lb,ub,p,inorder);
    }
};