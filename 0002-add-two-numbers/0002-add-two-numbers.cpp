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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        
        ListNode*ptr=dummy;
        
        while(l1 || l2 || carry)//koisa bhi ek null then we return
        {
            int sum=0;
            
            if(l1)
            {
               sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            
            ptr->next=new ListNode(sum%10);
            ptr=ptr->next;
        }
        return dummy->next;
    }
};