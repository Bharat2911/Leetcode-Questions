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
        
        
        while(n--)
        {
            ptr1=ptr1->next;
        }
        
        //this is a case when length of linked list and n are equal;
        if(ptr1==NULL)return ptr2->next;
        
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        ptr2->next=ptr2->next->next;
        
        return head;
    }
};