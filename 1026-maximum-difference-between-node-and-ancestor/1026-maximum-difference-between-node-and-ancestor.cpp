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
    int diff = INT_MIN;
    
    void getMax(TreeNode *root, int mx, int mi){
        
        if(root == NULL) return;
       
        mx = max(mx, root->val);
        mi = min(mi, root->val);
        
        diff = max(diff, mx - mi);
        
        getMax(root->left,mx,mi);
        getMax(root->right,mx,mi);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root) return 0;
        
        int mx = INT_MIN, mi = INT_MAX;

        getMax(root,mx,mi);
        
        return diff;
    }
};