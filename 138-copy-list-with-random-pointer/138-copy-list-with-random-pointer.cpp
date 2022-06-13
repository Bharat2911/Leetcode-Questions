/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
    Node* copyRandomList(Node* head) {
        
           Node* itr=head;
    Node* front=head;
    
    // STEP 1
    
    while(itr!=NULL){
        front=itr->next;
        Node* copy=new Node(itr->val);
        itr->next=copy;
        copy->next=front;
        itr=front;
    }
    
    // STEP 2
    
    itr=head;
    while(itr!=NULL){
        if(itr->random!=NULL){
            itr->next->random=itr->random->next;
        }
        itr=itr->next->next;
    }
    
    itr=head;
    Node* tempHead=new Node(0);
    Node* copy=tempHead;
    while(itr!=NULL){
        front=itr->next->next;
        copy->next=itr->next;
        itr->next=front;
        copy=copy->next;
        itr=front;
    }
    return tempHead->next;
    }
};