//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    
    int length(Node*head)
    {
        int l=0;
        Node*ptr=head;
        
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            l++;
        }
        
        return l;
    }
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           int len=length(head);
           
           if(n>len)
           {
               return -1;
           }
           
           Node*ptr1=head;
           Node*ptr2=head;
           
        //   int count=1;
          
        //   while(ptr1!=NULL and count!=n)
        //   {
        //       ptr1=ptr1->next;
        //       count++;
        //   }
        for(int i=1;i<n;i++)
        {
            ptr1=ptr1->next;
        }
          while(ptr1->next!=NULL)
          {
              ptr1=ptr1->next;
              ptr2=ptr2->next;
          }
          
          return ptr2->data;
           
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends