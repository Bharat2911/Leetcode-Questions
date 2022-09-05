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
        if(root==NULL)return;
        
        solve(root->left,ans);
        
        ans.push_back(root->val);
        
        solve(root->right,ans);
        
        }
    bool findTarget(TreeNode* root, int k) {
     
        vector<int>ans;
        
        if(root==NULL)
        {
            return false;
        }
        
        solve(root,ans);
        
        unordered_map<int,int>map;
        
        for(auto itr:ans)
        {
            int x=k-itr;
            
            if(map.find(x)!=map.end())
            {
                return true;
            }
            else map[itr]++;
        }
        return false;
    }
};