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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>res;
        
        if(root==NULL)
        {
            return res;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        int count=-1;
        
        //i will increment the count in end so that it check for level 0 also
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>ans;
            count++;
            while(sz--)
            {
                TreeNode*temp=q.front();
                q.pop();
                
                ans.push_back(temp->val);
                
                if(temp->left)
                {
                    q.push(temp->left);
                }
                
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            if(count&1)
            {
                reverse(ans.begin(),ans.end());
                res.push_back(ans);
            }
            else
            {
                res.push_back(ans);
            }
            
            // count++;
        }
        return res;
    }
};