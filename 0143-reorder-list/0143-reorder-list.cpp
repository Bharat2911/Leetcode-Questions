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
    ListNode*reverse(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
    }
    void merge(ListNode*l1,ListNode*l2)
    {
        while(l2)
        {
            ListNode*next=l1->next;
            
            l1->next=l2;
            l1=l2;
            l2=next;
        }
    }
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return ;
        }
        ListNode*fast=head;
        
        ListNode*slow=head;
        
        ListNode*prev=NULL;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        
        //reverse second half
        ListNode*l1=head;
        ListNode*l2=reverse(slow);
        
        merge(l1,l2);
    }
};