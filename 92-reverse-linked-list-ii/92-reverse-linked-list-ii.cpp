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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
       ListNode*start=head;
       ListNode*prev=NULL;
       ListNode*next;
       ListNode*end=head;
        
        int count=1;
        
        while(count!=left)
        {
            prev=start;
            start=start->next;
            count++;
        }
        
        count=1;
        while(count!=right)
        {
            
            end=end->next;
            count++;
        }
        next=end->next;
        end->next=NULL;
        
        ListNode*newhead=reverse(start);
        
        ListNode*curr=newhead;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            
        }
       if(prev!=NULL) prev->next=newhead;
        curr->next=next;
        if(left==1)return newhead;
        return head;
    }
};