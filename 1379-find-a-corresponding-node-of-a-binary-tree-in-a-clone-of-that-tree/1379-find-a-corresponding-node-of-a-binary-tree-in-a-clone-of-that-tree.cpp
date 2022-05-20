/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void store(TreeNode*root,vector<TreeNode*>&ans)
    {
        if(root==NULL)
        {
            return;
        }
       store(root->left,ans);
        ans.push_back(root);
        store(root->right,ans);
        
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        //store the nodes of clonned tree and then return the target
        vector<TreeNode*>ans;
        store(cloned,ans);
        
        int n=ans.size();
        
        for(int i=0;i<n;i++)
        {
            if(ans[i]->val==target->val)
            {
                return ans[i];
            }
        }
        return NULL;
    }
};