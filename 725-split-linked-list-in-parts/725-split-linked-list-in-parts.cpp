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
            curr=curr->next;
            l++;
        }
        return l;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int len=length(head);
        
        int extra=len%k;
        
        int element=len/k;
        
        vector<ListNode*>ans;
        
        ListNode*curr=head;
        ListNode*prev;
        
        while(curr)
        {
            int nodes=element;
            
            ans.push_back(curr);
            
            //elements jo per group me aane chaiye daal diye
            while(nodes>0)
            {
                prev=curr;
                curr=curr->next;
                nodes--;
            }
            
            //now push the extra elemnts we have
            if(extra>0)
            {
                extra--;
                prev=curr;
                curr=curr->next;
                
            }
            
            //now break the link list
           if(curr!=NULL)
           {
               prev->next=NULL;
               
           }
            
        }
        //case when k>len
        while(ans.size()!=k)
        {
            ans.push_back(NULL);
        }
        return ans;
    }
};