//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int length(Node*head)
    {
        if(head==NULL)
        {
            return 0;
        }
        
        Node*curr=head;
        
        int l=0;
        
        while(curr!=NULL){
            l++;
            curr=curr->next;
        }
        return l;
    }
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int l1=length(head1);
        int l2=length(head2);
        
        int d=abs(l1-l2);
        
        Node*ptr1=head1;
        Node*ptr2=head2;
        
        for(int i=0;i<d;i++)
        {
           if(l1>l2)
           {
               ptr1=ptr1->next;
           }
           
           if(l2>l1)
           {
               ptr2=ptr2->next;
           }
        }
        while(ptr1!=ptr2)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        return ptr1->data;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends