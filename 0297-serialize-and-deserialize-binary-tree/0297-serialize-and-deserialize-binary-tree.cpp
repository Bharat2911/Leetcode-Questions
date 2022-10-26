/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        //we will be doing the level order traversal here man jii
        string str="";
        
        if(root==NULL)
        {
            return str;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            
            if(temp==NULL)
            {
                str.append("#,");
            }
            else
            {
                str.append(to_string(temp->val)+',');
            }
            
          if(temp!=NULL)
          {
              q.push(temp->left);
            q.push(temp->right);
              
          }
        }
        cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       
        if(data.length()==0)
        {
            return NULL;
        }
        queue<TreeNode*>q;
        
        string str = "";

        stringstream s(data);

        getline(s, str, ',');
        
        TreeNode*root=new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            
            getline(s,str,',');//i got the left parr
            
            
            if(str=="#")
            {
                temp->left=NULL;
            }
            else
            {
                //temp ke left me node jiski value str hai
                TreeNode* leftnode=new TreeNode(stoi(str));
                temp->left=leftnode;
                
                q.push(leftnode);
            }
           
            
            //now get the right part
            getline(s,str,',');
            
            if(str=="#")
            {
                temp->right=NULL;
            }
            else
            {
                TreeNode*rightnode=new TreeNode(stoi(str));
                
                temp->right=rightnode;
                
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));