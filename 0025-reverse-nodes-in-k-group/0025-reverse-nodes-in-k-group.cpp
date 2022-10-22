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
    int length(ListNode*head)
    {
        int l=0;
        
        ListNode*curr=head;
        
        while(curr!=NULL)
        {
            curr=curr->next;
            l++;
        }
        
        return l;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL )
        {
            return NULL;
        }
        int len=length(head);
        
        if(k>len)return head;
        
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next;
        
        int count=0;
        
        while(curr!=NULL and count<k)
        {
            next=curr->next;
            
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next)
        {
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
    }
};