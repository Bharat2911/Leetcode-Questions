// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*p1=head;
        ListNode*p2=head->next;
        
        while(p2->next!=NULL)
        {
            p1=p1->next;
            p2=p2->next;
            
        }
        ListNode*new_tail=p1;
        ListNode*new_head=p1->next;
        
        new_tail->next=NULL;
        new_head->next=head;
        
        return new_head;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ListNode*> a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=new ListNode(x);
            if(i!=0){
                a[i-1]->next=a[i];
            }
        }
        ListNode *head=a[0];
        Solution ob;
        head=ob.moveToFront(head);
        while(head!=NULL){
            cout<<head->val;
            if(head->next!=NULL){
                cout<<" ";
            }
            head=head->next;
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends