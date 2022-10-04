/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Codec
{
    public:

       	// Encodes a tree to a single string.
        string serialize(TreeNode *root)
        {

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
        if (data.length() == 0)
        {
            return NULL;
        }
        queue<TreeNode*> q;

        string str = "";

        stringstream s(data);

        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            getline(s, str, ',');

            if (str == "#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode *newnode = new TreeNode(stoi(str));
                temp->left = newnode;

                q.push(newnode);
            }

           	//again line gives the next elemnt
            getline(s, str, ',');

            if (str == "#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode *newnode = new TreeNode(stoi(str));
                temp->right = newnode;

                q.push(newnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));