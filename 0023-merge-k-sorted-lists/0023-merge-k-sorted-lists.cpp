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
    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        if(!l1)return l2;
        if(!l2)return l1;
        
        ListNode*result=NULL;
        
        if(l1->val>=l2->val)
        {
            result=l2;
            result->next=merge(l1,l2->next);
        }
        else
        {
            result=l1;
            result->next=merge(l1->next,l2);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        
        if(n==0)
        {
            return NULL;
        }
        if(n==1)
        {
            return lists[0];
        }
        for(int i=1;i<n;i++)
        {
            lists[0]=merge(lists[0],lists[i]);
        }
        return lists[0];
    }
};