/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        //base case
        if(root==NULL)
        {
            return NULL;
        }
        //apply the level order and just connect the nodes
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                Node*temp=q.front();
                q.pop();
                
                if(i==sz-1)//means if we reach the end
                {
                    temp->next=NULL;
                }
                else
                {
                    temp->next=q.front();
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};