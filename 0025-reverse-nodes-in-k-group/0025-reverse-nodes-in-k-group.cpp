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
        ListNode*ptr=head;
        int l=0;
        
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            l++;
        }
        return l;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //base case
        if(head==NULL)
        {
            return NULL;
            
        }
        int l=length(head);
        
        if(k>l)return head;
        
        //reverse first k itrative
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*next;
        int count=1;
        
        while(curr!=NULL and count<=k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        //now recursivly reverse the rest of the linklist
        
        if(next)
        {
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
    }
};