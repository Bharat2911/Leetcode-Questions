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
    int i=0;
    
    TreeNode*solve(vector<int>&pre,vector<int>&in,int lb,int ub)
    {
        if(lb>ub)return NULL;
        
        TreeNode*root=new TreeNode(pre[i]);
        
        int idx=map[pre[i]];
        
        i++;
        
        root->left=solve(pre,in,lb,idx-1);
        
        root->right=solve(pre,in,idx+1,ub);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int>inorder=preorder;
        
        sort(inorder.begin(),inorder.end());
        
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