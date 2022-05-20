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
    TreeNode* getTargetCopy(TreeNode* root, TreeNode* cloned, TreeNode* target) {
        
        if(root==NULL)
        {
            return NULL;
        }
        queue<TreeNode*>q;
        
        q.push(cloned);
        
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            
            if(node->val==target->val)
            {
                return node;
                
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return NULL;
    }
};