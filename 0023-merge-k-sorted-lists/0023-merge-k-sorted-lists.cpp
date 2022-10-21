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
  class MyCmp{
        public:
            bool operator()(ListNode *l1,ListNode *l2){
                return l1->val>l2->val;
            }
    };
        
        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,MyCmp>pq;
        for(int i=0;i<l;i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        ListNode *head=new ListNode();
        ListNode* curr=head;
        while(!pq.empty()){
            curr->next=pq.top();
            curr=curr->next;
            pq.pop();
            if(curr->next!=NULL){
                pq.push(curr->next);
            }
        }
        return head->next;
        

        
    
    }
};