class Solution
{
    public:
        vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
        {

            int row = mat.size();

            int col = mat[0].size();

            vector<vector < int>> ans(row, vector<int> (col, INT_MAX));

            queue<pair<int, int>> q;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (mat[i][j] == 0)
                    {
                        ans[i][j] = 0;

                       	//multisource bfs here i am doing

                        q.push({ i,
                            j });
                    }
                }
            }
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

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int idx = 0; idx < 4; idx++)
                {
                    int newi = x + dx[idx];
                    int newj = y + dy[idx];

                    if (newi >= 0 and newi < row and newj >= 0 and newj < col and ans[x][y] + 1 < ans[newi][newj])
                    {
                        ans[newi][newj] = 1 + ans[x][y];

                        q.push({ newi,
                            newj });
                    }
                }
            }

            return ans;
        }
};