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
        
        ListNode*dummy_node=new ListNode(-1);
        ListNode*ptr=dummy_node;
        
        int carry=0;
        
        while(l1 || l2 || carry)
        {
            int sum=0;
            
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            
            ptr->next= new ListNode(sum%10);
            ptr=ptr->next;
        }
        return dummy_node->next;
    }
};