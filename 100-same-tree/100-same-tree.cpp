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
   bool matching(TreeNode *root, TreeNode *shoot)
    {
       	//couple of base cases

        if (root == NULL and shoot == NULL)
        {
            return true;
        }
        if (root == NULL || shoot == NULL)
        {
            return false;
        }

        if (root != NULL and shoot != NULL)
        {
           	//then we will check if the value match or ot

            bool left = matching(root->left, shoot->left);
            bool right = matching(root->right, shoot->right);

            if (root->val == shoot->val and left and right)
            {
                return true;
            }
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        
        return matching(p,q);
    }
};