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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode*ptr1=head;
        ListNode*ptr2=head;
        // ListNode*prev=NULL;
        
       for(int i=1;i<=n;i++)
       {
           ptr2=ptr2->next;
       }
        if(ptr2==NULL)return ptr1->next;
        while(ptr2->next!=NULL)
        {
            ptr1=ptr1->next;
           
            ptr2=ptr2->next;
        }
        ptr1->next=ptr1->next->next;
        
        return head;
    }
};