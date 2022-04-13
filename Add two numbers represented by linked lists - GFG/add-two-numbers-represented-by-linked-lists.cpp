// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
   Node* reverse(Node*head)
    {
        Node*curr=head;
        Node*prev=NULL;
        Node*next;
        
        while(curr!=NULL)
        {
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        //reverse the ll then add then again reverse the obtained ll 
        first=reverse(first);
        second=reverse(second);
        
        Node*dummy =new Node(0);
        Node*temp=dummy;
        int carry=0;
        int sum=0;
        
        while(first!=NULL || second!=NULL || carry)
        {
            if(first!=NULL)
            {
                sum+=first->data;
                first=first->next;
            }
            if(second!=NULL)
            {
                sum+=second->data;
                second=second->next;
                
            }
            sum+=carry;
            carry=sum/10;
            
            Node* newnode=new Node(sum%10);
            temp->next=newnode;
            temp=temp->next;
            sum=0;
            
        }
        dummy->next=reverse(dummy->next);
        return dummy->next;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends