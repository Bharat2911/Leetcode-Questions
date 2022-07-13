/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Codec
{
    public:

       	// Encodes a tree to a single string.
    
        string serialize(TreeNode *root)
        {

           	//doing level order traversal and stroe the value in string
            string str = "";

            if (root == NULL)
            {
                return str;
            }
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty())
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp == NULL) str.append("#,");
                else str.append(to_string(temp->val) + ',');

               	//since i also want the NULL value so no wheter wheter left or right is null or not just push since
               	//we also need null value;
                if (temp != NULL)
                {
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            cout << str;

            return str;
        }

   	// Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if(data.size()==0)
        {
            return NULL;
        }
        
        stringstream s(data);
        
        string str;
        
        getline(s,str,',');
        
        TreeNode*root=new TreeNode(stoi(str));
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            
            //next vala left and next se next vala right
            
            //for left
            getline(s,str,',');
            
            if(str=="#")
            {
                temp->left=NULL;
            }
            else 
            {
                TreeNode* leftnode=new TreeNode(stoi(str));
                temp->left=leftnode;
                
                q.push(leftnode);
            }
            
            //for right 
            getline(s,str,',');
            
            if(str=="#")
            {
                temp->right=NULL;
            }
            else
            {
                TreeNode* rightnode=new TreeNode(stoi(str));
                
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