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
    bool hasCycle(ListNode *head) {
        
        //in this we will use the slow and fast pointer
       ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL and fast->next!=NULL)
            
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};