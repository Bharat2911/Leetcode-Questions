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
    // /to handel that edge case we will make one condition
    int length(ListNode*head)
    {
        ListNode*curr=head;
        
        int len=0;
        
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //just for the edge case we need the length here
        int len=length(head);
        
        if(len<k)
        {
            return head;
        }
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next;
        
        int count=0;
        
        while(curr!=NULL and count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        //now send the recursion int th enext part
        if(next!=NULL)
        {
             head->next=reverseKGroup(next,k);
        }
       
        return prev;
    }
};