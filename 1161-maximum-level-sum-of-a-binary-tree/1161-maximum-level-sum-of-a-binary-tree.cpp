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
    int maxLevelSum(TreeNode* root) {
        
        int max_sum=INT_MIN;
        
        int level=1;
        
        int ans=0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            
            int sum=0;
            
            while(sz--)
            {
                TreeNode*node=q.front();
                q.pop();
                
                sum+=node->val;
                
                if(node->left)
                {
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            
            if(sum>max_sum)
            {
                ans=level;
                
                max_sum=sum;
            }
            
            level++;
        }
        
        return ans;
    }
};