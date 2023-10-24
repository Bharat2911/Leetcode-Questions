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
    vector<int> largestValues(TreeNode* root) {
        
        //we will be doing the level order traversal here man 
        
        vector<int>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            
            int maxi=INT_MIN;
            
            while(sz--)
            {
                TreeNode*node=q.front();
                
                q.pop();
                
                maxi=max(maxi,node->val);
                
                if(node->left)
                {
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            
            ans.push_back(maxi);
        }
        return ans;
    }
};