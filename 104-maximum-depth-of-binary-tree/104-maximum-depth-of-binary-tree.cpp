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
    int maxDepth(TreeNode* root) {
      
        //simply count the levels using level order traversal
        
        if(root==NULL)
        {
            return 0;
        }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int count=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            count++;
            
            while(sz--)
            {
                TreeNode*node=q.front();
                q.pop();
                
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return count;
    }
};