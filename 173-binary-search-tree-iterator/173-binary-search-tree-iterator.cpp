/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class BSTIterator
{
    public:

       	//using queue we will try to do this
    
    //time complexity of this is o(n);->using queue
    
    //time complexity O(h),h->height of a tree->using stack;
    
    
    
        queue<int> q;

    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        q.push(root->val);

        inorder(root->right);
    }
    BSTIterator(TreeNode *root)
    {

        inorder(root);
    }

    int next()
    {

        int top = q.front();
        q.pop();

        return top;
    }

    bool hasNext()
    {

        if (q.empty()) return false;
        return true;
    }
};

/**
 *Your BSTIterator object will be instantiated and called as such:
 *BSTIterator* obj = new BSTIterator(root);
 *int param_1 = obj->next();
 *bool param_2 = obj->hasNext();
 */