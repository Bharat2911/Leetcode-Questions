class Solution
{
    public:
    long long mod=1e9+7;
        int solve(int i, int j, vector<vector < int>> &grid, int k, int sum, int row, int col,vector<vector<vector<int>>>&dp)
        {
            sum=sum%k;
            if(i==row-1 and j==col-1)
            {
                if((grid[row-1][col-1]+sum)%k==0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            if(i>=row || j>=col)
            {
                return 0;
            }
            
            if(dp[i][j][sum]!=-1)return dp[i][j][sum];
            
            int down=solve(i+1,j,grid,k,sum+grid[i][j],row,col,dp);
            
            int right=solve(i,j+1,grid,k,sum+grid[i][j],row,col,dp);
            
            return dp[i][j][sum]=(down+right)%mod;
            
        }

    int numberOfPaths(vector<vector < int>> &grid, int k)
    {

        int row = grid.size();
        int col = grid[0].size();

        int i = 0;
        int j = 0;
        
    vector<vector<vector<int>>> dp(row , vector<vector<int>>(col , vector<int>(k , -1)));
        return solve(i, j, grid, k, 0, row, col,dp);
    }
};