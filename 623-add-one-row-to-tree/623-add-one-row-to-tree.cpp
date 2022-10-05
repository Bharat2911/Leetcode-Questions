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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1)
        {
            TreeNode*newroot=new TreeNode(val);
            
           newroot->left=root;
            
            return newroot;
            
        }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        int count=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            
            count++;
            
            while(sz--)
            {
                TreeNode*temp=q.front();
                q.pop();
                
                if(count!=depth-1)
                {
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
                else
                {
                    TreeNode*newnode1=new TreeNode(val);
                    
                    newnode1->left=temp->left;
                    
                    temp->left=newnode1;
                    
                    TreeNode*newnode2=new TreeNode(val);
                    
                    newnode2->right=temp->right;
                    
                    temp->right=newnode2;
                    
                }
            }
        }
         return root;
    }
};