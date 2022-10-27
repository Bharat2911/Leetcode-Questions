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
    vector<int> inorderTraversal(TreeNode* root) {
        
        //inorder ->left->root->right
        
        //morish traversal
        
        vector<int>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        TreeNode*curr=root;
        
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode*prev=curr->left;
                
                while(prev->right!=curr and prev->right!=NULL)
                {
                    prev=prev->right;
                }
                
                if(prev->right==NULL)
                {
                    //connect the thread
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    // break the  thread and get the answe
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};