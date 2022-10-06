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
    // pre->root->left->right
    unordered_map<int,int>map;
    int index=0;
    
    TreeNode*solve(vector<int>&preorder,vector<int>&inorder,int lb,int ub)
    {
        //base case
        if(lb>ub)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[index]);
        
        int search=map[preorder[index]];
        
        index++;
        
        root->left=solve(preorder,inorder,lb,search-1);
        
        root->right=solve(preorder,inorder,search+1,ub);
        
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n=preorder.size();
        vector<int>inorder=preorder;
        
        sort(inorder.begin(),inorder.end());
        
        for(int i=0;i<inorder.size();i++)
        {
            map[inorder[i]]=i;
        }
        
        int lb=0;
        int ub=n-1;
        return solve(preorder,inorder,lb,ub);
        
    }
};