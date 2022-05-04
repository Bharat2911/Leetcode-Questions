class Solution
{
    public:
        void bfs(int i, int j, vector<vector < int>> &grid, vector< vector< int >> &vis, vector< pair<int, int>> &v)
        {
            queue<pair<int, int>> q;
            int row = grid.size();
            int col = grid[0].size();
            q.push({ i,
                j });
            vis[i][j] = 1;
            v.push_back({ i,
                j });
            int dx[] = { 0,
                1,
                0,
                -1
            };
            int dy[] = { 1,
                0,
                -1,
                0
            };

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int idx = 0; idx < 4; idx++)
                {
                    int newi = x + dx[idx];
                    int newj = y + dy[idx];

                    if (newi >= 0 and newi < row and newj >= 0 and newj < col and!vis[newi][newj] and grid[newi][newj]==1)
                    {
                        vis[newi][newj] = 1;

                        v.push_back({ newi,
                            newj });

                        q.push({ newi,
                            newj });
                    }
                }
            }
        }
    int shortestBridge(vector<vector < int>> &grid)
    {

       	//since it is given that we only have the two island 
       	//so store the coordinates of both the island int seprate vector
       	//then apply distance formula between two points
       	//distance between p1(x1,y1) and p2(x2,y2) is(abs(x1-x2)+abs(y1-y2)-1)

        int row = grid.size();
        int col = grid[0].size();

        vector<pair<int, int>> island1;	//store the coordinates of one island
        vector<pair<int, int>> island2;	//sotre the coordinates of second island

        vector<vector < int>> vis(row, vector<int> (col, 0));

        int count = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] and grid[i][j] == 1)
                {
                    count++;

                    if (count == 1)	//we get the first island
                    {
                        bfs(i, j, grid, vis, island1);
                    }

                    if (count == 2)	//we get the second island
                    {
                        bfs(i, j, grid, vis, island2);
                    }
                }
            }
        }
       	//now we have to calculate the distance 
        int ans=INT_MAX;
     
        for(auto i :island1)
        for(auto j :island2) 
            ans=min(ans,(abs(i.first - j.first) + abs(i.second - j.second)-1));
        return ans;
    }
};