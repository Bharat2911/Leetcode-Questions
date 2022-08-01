class Solution
{
    public:
        int solve(int i, int j, int row, int col,vector<vector<int>>&dp)
        {
           	//base case (out of bound case)
            if (i < 0 || i >= row || j < 0 || j >= col)
            {
                return 0;
            }

            if (i == row - 1 and j == col - 1)	//reached the end point
            {
                return 1;
            }
            
            if(dp[i][j]!=-1)return dp[i][j];//means it is already seen
            

           	//look out all possiblities

            int down = solve(i + 1, j, row, col,dp);

            int right = solve(i, j + 1, row, col,dp);

            return dp[i][j]=down + right;
        }
    int uniquePaths(int m, int n)
    {

       	//more than one ways so we will use the recursion
        int i = 0;

        int j = 0;

        vector<vector < int>> dp(m, vector<int> (n, -1));

        return solve(i, j, m, n,dp);
    }
};