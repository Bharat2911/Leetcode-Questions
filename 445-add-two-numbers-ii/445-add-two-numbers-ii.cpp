/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverse(ListNode *head)
        {
            ListNode *curr = head;
            ListNode *prev = NULL;
            ListNode * next;

            while (curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
           	return prev;
        }
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {

       l1= reverse(l1);
        l2=reverse(l2);
        
        ListNode*dummyNode=new ListNode(-1);
        ListNode*ptr=dummyNode;
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
            
            ptr->next=new ListNode(sum%10);
            ptr=ptr->next;
        }
        dummyNode->next=reverse(dummyNode->next);
        return dummyNode->next;
    }
};