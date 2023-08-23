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
     void solve(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            
            TreeNode*temp;
            
            while(sz--)
            {
                temp=q.front();
                q.pop();
                
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(temp->val);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
       
       if(root==NULL)
       {
           return ans;
       }
       
       solve(root,ans);
       
       return ans;
    }
};