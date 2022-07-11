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
        int widthOfBinaryTree(TreeNode *root)
        {

           	//we will be using the concept of indexing here
            if (root == NULL)
            {
                return 0;
            }
            queue<pair<TreeNode*, int>> q;

            int ans = 0;

            q.push({ root,
                0 });

            while (!q.empty())
            {

               	//ans right_most_index - left_most_index +1

                int right_idx = q.back().second;
                int left_idx = q.front().second;

                ans = max(ans, right_idx - left_idx + 1);

                int sz = q.size();

                while (sz--)
                {
                    TreeNode *temp = q.front().first;
                    int index = q.front().second;
                    q.pop();

                    if (temp->left)
                    {
                        q.push({ temp->left,
                           (long long) 2 *index + 1 });
                    }
                    if (temp->right)
                    {
                        q.push({ temp->right,
                          (long long)  2 *index + 2 });
                    }
                }
            }
            return ans;
        }
};