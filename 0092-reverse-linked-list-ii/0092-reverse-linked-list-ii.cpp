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
    ListNode*reverse(ListNode*head,ListNode*right)
    {
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*next;
        
        while(curr!=right)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int s=left;
        
        ListNode*start=head;
        ListNode*end=head;
        ListNode*x=NULL;
        ListNode*y;
        left-=1;
        // right=1;
        
        while(left--)
        {
            x=start;
            start=start->next;
        }
        
        while(right--)
        {
            end=end->next;
        }
        
        y=end;
        // end->next=L
        
        
        ListNode*reverseHead=reverse(start,end);
        
      
       cout<<reverseHead->val;
        
        
        // connect the 
        
        if(x!=NULL)
        {
            x->next=reverseHead;
            
        }
        start->next=y;
        
        if(s==1)
        {
            return reverseHead;
        }
        
        return head;
    }
};