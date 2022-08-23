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
    //function for reversing the linked list
    ListNode*reverse(ListNode*head)
    {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
        }
        ListNode*prev=reverse(slow);
        
        while(head!=NULL and prev!=NULL)
        {
            if(head->val==prev->val)
            {
                head=head->next;
                prev=prev->next;
            }
            else
            {
                return false;
                break;
            }
        }
        return true;
    }
};