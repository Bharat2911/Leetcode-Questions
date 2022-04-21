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
class BSTIterator {
public:
    //this is an optimised approach 
    //t.c=O(1);
    //s.c=O(h);
    
    stack<TreeNode*>st;
    
    BSTIterator(TreeNode* root) {
        
        push_left(root);
        
    }
    void push_left(TreeNode*root)
    {
        //pushes left element into the stack
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        
    }
    int next() {
        
        TreeNode*top=st.top();
        st.pop();
        
        push_left(top->right);
        
        return top->val;
    }
    
    bool hasNext() {
        
        if(!st.empty())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */