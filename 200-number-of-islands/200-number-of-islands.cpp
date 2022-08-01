class Solution
{
    public:
        void solve(int i, int j, vector<vector < char>> &grid, int row, int col, vector< vector< bool>> &vis)
        {
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

            queue<pair<int, int>> q;

            vis[i][j] = true;
            q.push({ i,
                j });

            while (!q.empty())
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for (int idx = 0; idx < 4; idx++)
                {
                    int newi = x + dx[idx];
                    int newj = y + dy[idx];

                    if (newi >= 0 and newi < row and newj >= 0 and newj < col and!vis[newi][newj] and grid[newi][newj] == '1')
                    {
                        vis[newi][newj] = true;

                        q.push({ newi,
                            newj });
                    }
                }
            }
        }
    int numIslands(vector<vector < char>> &grid)
    {

        int row = grid.size();
        int col = grid[0].size();

        int count = 0;

        vector<vector < bool>> vis(row, vector<bool> (col, false));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] and grid[i][j] == '1')
                {
                    count++;
                    solve(i, j, grid, row, col, vis);
                }
            }
        }
        return count;
    }
};