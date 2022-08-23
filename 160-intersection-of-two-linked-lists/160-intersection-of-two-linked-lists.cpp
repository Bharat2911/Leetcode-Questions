/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode*ptr1=headA;
        ListNode*ptr2=headB;
        
        int l1=length(headA);
        int l2=length(headB);
        
        int d=abs(l1-l2);
        
       if(l1>l2)
       {
           for(int i=0;i<d;i++)
           {
               ptr1=ptr1->next;
           }
       }
        if(l2>l1)
        {
            for(int i=0;i<d;i++)
            {
                ptr2=ptr2->next;
            }
        }
        
        while(ptr1!=ptr2)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr2;
        
    }
};