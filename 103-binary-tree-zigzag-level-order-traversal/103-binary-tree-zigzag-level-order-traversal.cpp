/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {

            vector<vector < int>> ans;

            if (root == NULL)
            {
                return ans;
            }

            int count = -1;

            queue<TreeNode*> q;

            q.push(root);

            while (!q.empty())
            {
                int sz = q.size();

                vector<int> res;

                while (sz--)
                {
                    TreeNode *temp = q.front();
                    q.pop();

                    res.push_back(temp->val);

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }

                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }

                count++;
                if (count & 1)
                {
                    reverse(res.begin(), res.end());
                }
                ans.push_back(res);
            }
            return ans;
        }
};