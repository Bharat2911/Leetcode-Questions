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
    int widthOfBinaryTree(TreeNode* root) {
            if(root==NULL)return 0;
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        int ans=1;
        
        while(!q.empty())
        {
            int left_idx=q.front().second;
            int right_idx=q.back().second;
            int sz=q.size();
            
            ans=max(ans,right_idx-left_idx+1);
            
            while(sz--)
            {
                TreeNode*temp=q.front().first;
                int idx=q.front().second;
                q.pop();
                
                if(temp->left)
                {
                    q.push({temp->left,(long long)2*idx+1});
                }
                if(temp->right)
                {
                    q.push({temp->right,(long long)2*idx+2});
                }
            }
            
            
        }
        return ans;
    }
};