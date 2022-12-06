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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode*ptr=head;
        
        ListNode*dummy_odd=new ListNode(-1);
        ListNode*dummy_even=new ListNode(-1);
        
        ListNode*ptr1=dummy_odd;
        ListNode*ptr2=dummy_even;
        
        int count=1;
        
        while(ptr!=NULL)
        {
            if(count&1)//if odd index 
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
                ptr=ptr->next;
            }
            else
            {
                ptr2->next=ptr;
                ptr2=ptr2->next;
                ptr=ptr->next;
            }
            count++;
        }
        //now connect the links man
        ptr1->next=dummy_even->next;
        ptr2->next=NULL;
        
        return dummy_odd->next;
    }
};