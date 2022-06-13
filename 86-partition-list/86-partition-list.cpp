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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode*less=new ListNode(-1);
        ListNode*pl=less;
        
        
        
        ListNode*greater=new ListNode(-1);
        ListNode*pg=greater;
        
        ListNode*curr=head;
        
        while(curr!=NULL)
        {
            if(curr->val<x)
            {
                pl->next=curr;
                curr=curr->next;
                pl=pl->next;
            }
            
            else
            {
                pg->next=curr;
                pg=pg->next;
                curr=curr->next;
            }
        }
        pl->next=greater->next;
       
        pg->next=NULL;
        
        return less->next;
        
    }
};