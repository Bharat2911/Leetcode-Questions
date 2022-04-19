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
    void inorder(TreeNode*root,vector<TreeNode*>&ans)
    {
        if(root==NULL)return ;
        inorder(root->left,ans);
        ans.push_back(root);
        inorder(root->right,ans);
        
    }
    void recoverTree(TreeNode* root) {
        
         vector<TreeNode*>ans;
        
        inorder(root,ans);
        
        //we will be using the concept that inorder of bst is always sortes
        int i=-1;
        int j=-1;
        
        for(int k=0;k<ans.size()-1;k++)
        {
            if(ans[k]->val>ans[k+1]->val)
            {
                if(i==-1)
                {
                    i=k;
                    j=k+1;
                }
                else
                {
                    j=k+1;
                }
            }
        }
        swap(ans[i]->val,ans[j]->val);
        
    }
};