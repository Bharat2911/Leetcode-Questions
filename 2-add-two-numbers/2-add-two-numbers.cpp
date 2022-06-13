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
        
        ListNode*head1=l1;
        ListNode*head2=l2;
        
        int carry=0;
        
        ListNode*dummy_node=new ListNode(-1);
        
        ListNode*ptr=dummy_node;
        
        while(head1 || head2 || carry)
        {
            int sum=0;
            
            if(head1!=NULL)
            {
                sum+=head1->val;
                head1=head1->next;
            }
            if(head2!=NULL)
            {
                sum+=head2->val;
                head2=head2->next;
            }
            sum+=carry;
            carry=sum/10;
            
            ptr->next=new ListNode(sum%10);
            ptr=ptr->next;
        }
        return dummy_node->next;
    }
};