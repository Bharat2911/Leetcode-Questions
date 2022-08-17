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
        ListNode*curr=head;
        
        int l=0;
        
        while(curr!=NULL)
        {
            l++;
            curr=curr->next;
        }
        
        return l;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len=length(head);
        
        if(len<k)return head;//base case
        
        //reverse the first k node using itrative method then apply recursive 
        
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
        
        if(next)
        {
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
        
    }
};