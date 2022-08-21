/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int amountOfTime(TreeNode *root, int start)
        {

            unordered_map<int, vector < int>> m;

            set<int> vis;

            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())	//adding neighbours
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                {
                    m[t->val].push_back(t->left->val);
                    m[t->left->val].push_back(t->val);
                    q.push(t->left);
                }
                if (t->right)
                {
                    m[t->val].push_back(t->right->val);
                    m[t->right->val].push_back(t->val);
                    q.push(t->right);
                }
            }
            int ans=0;
            
            queue<pair<int, int>> pq;

            pq.push({ start,
                0 });
            vis.insert(start);

            while (!pq.empty())
            {
                int node = pq.front().first;
                int level = pq.front().second;
                pq.pop();

                ans = max(ans, level);

                for (auto itr: m[node])
                {
                    if (vis.find(itr) == vis.end())
                    {
                        vis.insert(itr);
                        pq.push({ itr,
                            level + 1 });
                    }
                }
            }
            return ans;
        }
};