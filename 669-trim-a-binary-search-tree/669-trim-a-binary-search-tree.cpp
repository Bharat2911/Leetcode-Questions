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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
          //base csae
        if(root==NULL)
        {
            return NULL;
            
        }
        
        if(root->val<low)
        {
            return trimBST(root->right,low,high);
        }
        if(root->val>high)
        {
            return trimBST(root->left,low,high);
        }
        
        //do this whole stuff on the left subtree
        root->left=trimBST(root->left,low,high);
        
        //similarly do this whole stuff on the right subtree
      root->right=trimBST(root->right,low,high);
        
        return root;
        
    }
};