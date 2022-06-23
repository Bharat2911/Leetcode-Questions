class Solution
{
    public:
        void topo(int start, vector<int> adj[], stack<int> &s, vector<bool> &vis)
        {
            vis[start] = true;

            for (auto itr: adj[start])
            {
                if (!vis[itr])
                {
                    vis[itr] = true;

                    topo(itr, adj, s, vis);
                }
            }
            s.push(start);
        }
    bool iscycle(vector<int> adj[], int n)
    {

        vector<int> indegree(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (auto x: adj[i])
            {
                indegree[x]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            count++;
            for (auto x: adj[i])
            {
                indegree[x]--;

                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        if (count == n) return false;
        return true;
    }
    vector<int> findOrder(int n, vector<vector < int>> &p)
    {

        vector<int> ans;
        stack<int> s;
        vector<bool> vis(n, false);
        vector<int> adj[n];

        for (int i = 0; i < p.size(); i++)
        {
            int u = p[i][0];
            int v = p[i][1];

            adj[u].push_back(v);
        }

        if (iscycle(adj, n)) return ans;

        for (int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                topo(i, adj, s, vis);
            }
            
        }
        while (!s.empty())
        {
            int t = s.top();
            s.pop();
            ans.push_back(t);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};