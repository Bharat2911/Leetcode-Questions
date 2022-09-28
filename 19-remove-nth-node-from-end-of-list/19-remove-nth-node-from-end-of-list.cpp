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
        
        ListNode*ptr=head;
        
        while(ptr!=NULL)
        {
            l++;
            ptr=ptr->next;
        }
        return l;
        
    }
        ListNode* removeNthFromEnd(ListNode *head, int n)
        {
            
            int l=length(head);
            
            if(n>l)
            {
                return NULL;
            }
            if(n==l)
            {
                return head->next;
            }
            ListNode *prev = NULL;
            ListNode *ptr1 = head;
            ListNode *ptr2 = head;

            int count = 1;
            
            while (ptr1 != NULL and count < n)
            {
                ptr1 = ptr1->next;
                count++;
            }
           
            while (ptr1->next != NULL)
            {
                prev=ptr2;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            prev->next=prev->next->next;

            return head;
        }
};