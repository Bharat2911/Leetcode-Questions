class Solution
{
    public:
        int ans = 0;

    void solve(int i, int j, vector<vector < int>> &grid, vector< vector< int>> &vis, int row, int col)
    {
        queue<pair<int, int>> q;

        int dx[4] = { 0,
            1,
            0,
            -1
        };
        int dy[4] = { 1,
            0,
            -1,
            0
        };

        q.push({ i,
            j });
        vis[i][j] = 1;
        int count = 1;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int idx = 0; idx < 4; idx++)
            {
                int newi = x + dx[idx];
                int newj = y + dy[idx];

                if (newi >= 0 and newi < row and newj >= 0 and newj < col and!vis[newi][newj] and grid[newi][newj] == 1)
                {
                    vis[newi][newj] = 1;
                    count++;

                    q.push({ newi,
                        newj });
                }
            }
            ans = max(ans, count);
        }
    }
    int maxAreaOfIsland(vector<vector < int>> &grid)
    {

       	//abhi tak me bahar se count kar rha tha 
       	//isme andar se count karke max one vala nikal lo
        int row = grid.size();
        int col = grid[0].size();

        vector<vector < int>> vis(row, vector<int> (col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 and!vis[i][j])
                {

                    solve(i, j, grid, vis, row, col);
                }
            }
        }
        return ans;
    }
};