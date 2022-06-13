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
    ListNode* deleteDuplicates(ListNode* head) {
        //usign the map we will be doing this 
        // T.C = O(n)
        //S.C=o(n)   since using the map
        ListNode*curr=head;
        //since map store in sorted order bro
        map<int,int>map;
        
        while(curr!=NULL)
        {
            map[curr->val]++;curr=curr->next;
        }
        ListNode*dummy=new ListNode(-1);
        ListNode*ptr=dummy;
        
        for(auto itr:map)
        {
            if(itr.second==1)
            {
                ptr->next=new ListNode(itr.first);
                ptr=ptr->next;
            }
        }
        return dummy->next;
    }
};