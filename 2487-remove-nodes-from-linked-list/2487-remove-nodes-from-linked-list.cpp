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
    //T.C=O(n)
    //S.C=O(n)
    ListNode* removeNodes(ListNode* head) {
        
        vector<int>arr;
        
        ListNode*curr=head;
        
        while(curr!=NULL)
        {
            arr.push_back(curr->val);
            curr=curr->next;
        }
        //now apply concept of next greater elemnt
        int n=arr.size();
        
        vector<int>ans(n);
        
        stack<int>st;
        
        ans[n-1]=-1;
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and arr[i]>=st.top())
            {
                st.pop();
            }
            int x=st.empty()?-1:st.top();
            ans[i]=x;
            
            st.push(arr[i]);
        }
        ListNode*dummy=new ListNode(-1);
        ListNode*ptr=dummy;
        
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                ptr->next=new ListNode(arr[i]);
                ptr=ptr->next;
            }
        }
        return dummy->next;
    }
};