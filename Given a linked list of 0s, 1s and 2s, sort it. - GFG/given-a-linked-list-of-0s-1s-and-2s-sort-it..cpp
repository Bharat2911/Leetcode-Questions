// { Driver Code Starts
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

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node*temp=head;
        
        Node*zero=new Node(-1);//new node
        
        Node*p0=zero;
        
        Node*one=new Node(-1);
        
        Node*p1=one;
        
        Node*two=new Node(-1);
        
        Node*p2=two;
        
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                p0->next=temp;
                p0=p0->next;
                temp=temp->next;
            }
            else if(temp->data==1)
            {
                p1->next=temp;
                p1=p1->next;
                temp=temp->next;
            }
            else
            {
                p2->next=temp;
                p2=p2->next;
                temp=temp->next;
            }
        }
        p0->next=(one->next)? (one->next) : two->next;
        
        p1->next=two->next;
        p2->next=NULL;
        
        delete zero;
        delete one;
        delete two;
        return zero->next;
        
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends