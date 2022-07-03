class Solution
{
    public:
        int solve(int i, int j, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {
           	//in four direcxtions 
            int row = matrix.size();
            int col = matrix[0].size();
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
            int ans = 1;
            
            if (dp[i][j] != -1) return dp[i][j];

            for (int idx = 0; idx < 4; idx++)
            {
                int newi = i + dx[idx];
                int newj = j + dy[idx];

                if (newi >= 0 and newi < row and newj >= 0 and newj < col and matrix[newi][newj] > matrix[i][j])
                {
                    int count = 1 + solve(newi, newj, matrix,dp);

                    ans = max(ans, count);
                }
            }
            return dp[i][j]=ans;
        }
    int longestIncreasingPath(vector<vector < int>> &matrix)
    {

        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        vector<vector < int>> dp(row, vector<int> (col, -1));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans;
    }
};