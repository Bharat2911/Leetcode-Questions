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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>res;
            
            while(sz--)
            {
                Node*temp=q.front();
                q.pop();
                
                res.push_back(temp->val);
                
                //itrate thriught its childerens
                vector<Node*>v=temp->children;
                
                for(int i=0;i<v.size();i++)
                {
                    q.push(v[i]);
                }
            }
            ans.push_back(res);
            
        }
        return ans;
    }
};