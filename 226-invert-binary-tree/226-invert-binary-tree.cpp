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
    TreeNode* invertTree(TreeNode* root) {
        
        
        //if we observe then we can say that we simply have to swap the left subtree and the right subtree
        
        if(root==NULL)
        {
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left,root->right);
        
        return root;
        
    }
};