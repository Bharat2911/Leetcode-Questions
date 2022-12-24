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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        int n=nums.size();
        ListNode*curr=head;
        
        unordered_map<int,int>map;
        
        for(auto itr:nums)
        {
            map[itr]++;
        }
        
        int count=0;
        
        
        while(curr!=NULL)
        {
            if(map.find(curr->val)!=map.end())
            {
                while(curr->next and  map.find(curr->next->val)!=map.end())
                {
                    curr=curr->next;
                }
                count++;
            }
            curr=curr->next;
      
        }
        return count;
    }
};