class Solution
{
    public:
       	//this question will boils down to minimum distance between source and destination
       	//we use bfs because bfs gives the minimum distance
        int minJumps(vector<int> &arr)
        {

            int n = arr.size();

            queue<int> q;
            int ans = 0;

            int target = n - 1;

            vector<int> vis(n, 0);

            unordered_map<int, vector < int>> map;

            for (int i = 0; i < n; i++)
            {
                map[arr[i]].push_back(i);
            }

            q.push(0);
            vis[0] = 1;

            while (!q.empty())
            {
                int sz = q.size();
                ans++;

                while (sz--)
                {
                    int idx = q.front();
                    q.pop();

                    if (idx == target)
                    {
                        return ans - 1;
                    }
                    vector<int> &next = map[arr[idx]];
                    next.push_back(idx + 1);
                    next.push_back(idx - 1);

                    for (auto itr: next)
                    {
                        if (itr >= 0 and itr < n and!vis[itr])
                        {
                            vis[itr] = 1;
                            q.push(itr);
                        }
                    }
                    map[arr[idx]].clear();
                }
            }
            return -1;
        }
};