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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode*first=0;
        ListNode*last=0;
        ListNode*ptr1=head;
        ListNode*ptr2=head;
        
        
        
        int count=1;
        while(ptr1!=NULL and count<k)
        {
            ptr1=ptr1->next;
            count++;
            
        }
        first=ptr1;//ptr1 is now pointing on the kth node from dtatring
        
        while(ptr1->next!=NULL  )
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            
        }
        last=ptr2;//ptr2 is now pointing on the k th node from last
        
        swap(first->val,last->val);
        
        return head;
        
        
    }
};