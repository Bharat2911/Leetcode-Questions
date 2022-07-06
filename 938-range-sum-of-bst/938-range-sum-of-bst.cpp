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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        //we will use level order traversal here 
        int sum=0;
        
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
                TreeNode*node=q.front();
                q.pop();
                
                if(node->val>=low and node->val<=high)
                {
                    sum+=node->val;
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
        }
        return sum;
    }
};