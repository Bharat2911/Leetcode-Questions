/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

//asked in AMAZON
class Solution
{
    public:
       	//this will match the values of both tree
        bool ans = false;

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

   	//now we have to traverse the whole tree ans keep on matching
   	//and we will traverse in the inorder manner

    void inorder(TreeNode *root, TreeNode *shoot)
    {
        if (root == NULL)
        {
            return;
        }

       	//left->root->right

        inorder(root->left, shoot);

        bool x = matching(root, shoot);

        if (x == true)
        {
            ans = true;
        }

        inorder(root->right, shoot);
    }

    bool isSubtree(TreeNode *root, TreeNode *shoot)
    {
        if (root == NULL and shoot == NULL)
        {
            return true;
        }
        if (root == NULL || shoot == NULL)
        {
            return false;
        }

        inorder(root, shoot);

        return ans;
    }
};