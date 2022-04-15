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
        
        //usig the properth of bst 
        // ->if root->val is less than low then return right nodes because all node right to low are higher
        // ->if root->val is higher than high then return nodes less than high 
        
        //base case
        if(root==NULL)
        {
            return NULL;
            
        }
        //doing the inorder traversal
        
        
        // move left
        root->left=trimBST(root->left,low,high);
        
        //managing the operation we do on each nodee
        if(root->val<low)
        {
            return trimBST(root->right,low,high);
        }
        if(root->val>high)
        {
            return trimBST(root->left,low,high);
        }
        
        //move right
        root->right=trimBST(root->right,low,high);
        
        
        
        return root;
        
    }
};