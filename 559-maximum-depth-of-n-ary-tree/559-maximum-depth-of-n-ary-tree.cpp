/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        
        //count each level we will get our ans
        if(root==NULL)
        {
            return 0;
        }
        
        queue<Node*>q;
        
        q.push(root);
        
        int count=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
                Node*temp=q.front();
                
                q.pop();
                
                vector<Node*>v=temp->children;
                
                for(int i=0;i<v.size();i++)
                {
                    q.push(v[i]);
                }
            }
            count++;
        }
        return count;
    }
};