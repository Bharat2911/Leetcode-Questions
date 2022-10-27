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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>pre;
        
        vector<int>inorder;
        
        vector<int>post;
        
        if(root==NULL)
        {
            return pre;
            
        }
        
        stack<pair<TreeNode*,int>>st;
        
        st.push({root,1});
        
        while(!st.empty())
        {
            int num=st.top().second;
            TreeNode*node=st.top().first;
            
            st.pop();
            
            //we only have the cases cover those 3 cases man
            
            if(num==1)
            {
                pre.push_back(node->val);
                num++;
                
                st.push({node,num});
                
                if(node->left!=NULL)
                {
                    st.push({node->left,1});
                }
            }
            else if(num==2)
            {
                inorder.push_back(node->val);
                num++;
                
                st.push({node,num});
                
                if(node->right!=NULL)
                {
                    st.push({node->right,1});
                }
            }
            else
            {
                post.push_back(node->val);
            }
        }
        return pre;
    }
};