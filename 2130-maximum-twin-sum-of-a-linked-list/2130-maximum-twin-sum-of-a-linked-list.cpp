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
class Solution {
public:
    int pairSum(ListNode* head) {
        
        vector<int>ans;
        ListNode*curr=head;
        
        while(curr!=NULL)
        {
            ans.push_back(curr->val);
            curr=curr->next;
        }
        int n=ans.size();
        int sum=0;
        int res=0;
        
        for(int i=0;i<=(n/2)-1;i++)
        {
            sum=ans[i]+ans[n-i-1];
            res=max(res,sum);
        }
        return res;
    }
};