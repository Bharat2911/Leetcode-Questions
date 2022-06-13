// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    Node *zigZag(Node* head)
    {
     // your code goes here
     int idx=1;
     Node*ptr1=head;
     Node*ptr2=head->next;
     
     while( ptr2!=NULL)
      {
          if(idx&1)//menas wehen we are at odd pos
          {
              if(ptr1->data>ptr2->data)
              {
                  swap(ptr1->data,ptr2->data);
                  
              }
          }
          else if(idx%2==0)
          {
              if(ptr2->data>ptr1->data)
              {
                  swap(ptr1->data,ptr2->data);
                  
              }
          }
          ptr1=ptr1->next;
          ptr2=ptr2->next;
          idx++;
      }
      return head;
    }
};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends