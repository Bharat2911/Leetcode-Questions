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
    ListNode*merge(ListNode*head1,ListNode*head2)
    {
        if(head1==NULL)
        {
            return head2;
        }
        if(head2==NULL)
        {
            return head1;
            
        }
        ListNode*result=NULL;
        
        if(head1->val>=head2->val)
        {
            result=head2;
            result->next=merge(head1,head2->next);
        }
        else
        {
            result=head1;
            result->next=merge(head1->next,head2);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
        {
            return NULL;
        }
        ListNode*head=lists[0];
        
        for(int i=1;i<lists.size();i++)
        {
            head=merge(head,lists[i]);
        }
        
        return head;
        
        
    }
};