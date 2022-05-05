class Solution
{
    public:
        int maxDistance(vector<vector < int>> &grid)
        {

           	//this is the multisoure bfs
            int row = grid.size();
            int col = grid[0].size();

           	//making an anser matrux
            vector<vector < int>> ans(row, vector<int> (col, INT_MAX));	//initially filled with infinity

            queue<pair<int, int>> q;

           	//push all the coordinates of one in quwuw

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({ i,
                            j });
                        ans[i][j] = 0;	//since distance of 1 from 1 is 0(everytime)
                    }
                }
            }

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
            int dist=0;
            

            while (!q.empty())
            {
                int sz = q.size();
                dist++;

                while (sz--)
                {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();

                    for (int idx = 0; idx < 4; idx++)
                    {
                        int newi = i + dx[idx];
                        int newj = j + dy[idx];

                        if (newi >= 0 and newi < row and newj >= 0 and newj < col and ans[i][j] + 1 < ans[newi][newj])
                        {
                            ans[newi][newj] = ans[i][j] + 1;
                            q.push({ newi,
                                newj });
                        }
                    }
                }
               	//            
            }
           	//now find the max in ans matrix
            
            
            return dist>1?dist-1:-1;
        }
};