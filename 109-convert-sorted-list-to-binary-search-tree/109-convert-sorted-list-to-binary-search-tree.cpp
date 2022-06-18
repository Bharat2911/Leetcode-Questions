/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int>&inorder,int lb,int ub)
    {
        //base case
        if(lb>ub)return NULL;
        int n=inorder.size();
        
        int idx=(lb+ub)/2;
        
        TreeNode*root=new TreeNode(inorder[idx]);
        
        root->left=solve(inorder,lb,idx-1);
        root->right=solve(inorder,idx+1,ub);
        
        return root;
        
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        //list is sorted means we have given the inorder traversal
        vector<int>inorder;
        
        ListNode*curr=head;
        
        while(curr!=NULL)
        {
            inorder.push_back(curr->val);
            curr=curr->next;
        }
        int n=inorder.size();
        
        return solve(inorder,0,n-1);
    }
};