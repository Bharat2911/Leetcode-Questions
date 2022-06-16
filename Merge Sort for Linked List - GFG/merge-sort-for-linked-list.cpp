// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node*merge(Node*head1,Node*head2)
    {
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        Node*result=NULL;
        
        if(head1->data<=head2->data)
        {
            result=head1;
            result->next=merge(head1->next,head2);
        }
        else
        {
            result=head2;
            result->next=merge(head1,head2->next);
        }
        return result;
    }

    Node* mergeSort(Node* head) {
        // your code here
        //split from middle
        if(head==NULL || head->next==NULL)
        {
            return head;
            
        }
        Node*slow=head;
        Node*fast=head;
        
        while(fast!=NULL and fast->next!=NULL and fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        Node*new_head=slow->next;
        slow->next=NULL;
        
        Node*a=mergeSort(head);
        Node*b=mergeSort(new_head);
        
        return merge(a,b);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends