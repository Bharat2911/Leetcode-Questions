/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    
    	//Approach 1 (T.C=O(n)  and S.C=O(n))
    
//         TreeNode *prev = NULL;
//     void flatten(TreeNode *root)
//     {

       

//         if (root == NULL) return;

//         flatten(root->right);
//         flatten(root->left);

//         root->right = prev;
//         root->left = NULL;
        
//         prev=root;
//     }
    
    //Approach 2(T.C=O(n) and S.C=O(1))-->morish traversal se
    
    void flatten(TreeNode *root)
    {
        TreeNode*curr=root;
        
        while(curr)
        {
            
            if(curr->left!=NULL)
            {
                TreeNode*prev=curr->left;
                
                while(prev->right)
                {
                    prev=prev->right;
                }
                
                prev->right=curr->right;
                curr->right=curr->left;
                
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};