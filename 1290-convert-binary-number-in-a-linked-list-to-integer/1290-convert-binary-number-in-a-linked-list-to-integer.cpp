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
    int getDecimalValue(ListNode* head) {
        
        ListNode*temp=head;
        
        string ans="";
        
        
        while(temp!=NULL)
        {
            ans+=to_string(temp->val);
            temp=temp->next;
            
        }
        
        //now itrate in vector to convert it in decimal
        cout<<ans<<endl;
        
        //using stoi to convert the string to base 2
        
        int result=stoi(ans,0,2);
        
        return result;
        
    }
};