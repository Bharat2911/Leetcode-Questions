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
        vector<double> averageOfLevels(TreeNode *root)
        {

            vector<vector < int>> ans;

            vector<double> res;

            if (root == NULL)
            {
                return res;
            }

            queue<TreeNode*> q;

            q.push(root);

            while (!q.empty())
            {
                int sz = q.size();
                vector<int> x;

                while (sz--)
                {
                    TreeNode *temp = q.front();

                    q.pop();

                    x.push_back(temp->val);
                    
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
                ans.push_back(x);
            }
            
            for(auto itr:ans)
            {
                long long sum=0;
                
                long long count=0;
                
                for(auto y:itr)
                {
                    count++;
                    
                    sum+=y;
                }
                
                double z=(double)sum/(double)count;
                
                res.push_back(z);
            }
            return res;
        }
};