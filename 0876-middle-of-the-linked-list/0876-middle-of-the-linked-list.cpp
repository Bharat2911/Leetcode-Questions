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
            ptr=ptr->next;
            l++;
        }
        return l;
            
    }
    ListNode* middleNode(ListNode* head) {
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
        
    }
};