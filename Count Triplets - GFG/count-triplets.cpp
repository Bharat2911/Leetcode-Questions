// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    //sortd 
    //my approach 
    //T.C ==O(n^2)//traverseing only once
    //s.C==O(1);
    
    Node*p1=head;
    vector<int>v;
    int count=0;
    
    while(p1!=NULL)
    {
        v.push_back(p1->data);
        p1=p1->next;
    }
    int n=v.size();
    
    for(int i=0;i<v.size()-2;i++)
    {
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
              int sum=v[i]+v[j]+v[k];
        
        if(sum<x)
        {
            j++;
        }
        else if(sum>x)
        {
            k--;
        }
        else
        {
            count++;
            j++;
            k--;
        }
        }
      
    }
    return count;
} 