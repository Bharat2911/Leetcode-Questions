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
    void solve(TreeNode*root,vector<vector<int>>&ans)
    {
        if(root==NULL)
        {
            return ;
        }
        int level=1;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            
            vector<int>res;
            
            while(sz--)
            {
                TreeNode*node=q.front();
                q.pop();
                
                res.push_back(node->val);
                
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(level%2==0)
            {
                reverse(res.begin(),res.end());
            }
            
            ans.push_back(res);
            
            level++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        solve(root,ans);
        
        return ans;
    }
};