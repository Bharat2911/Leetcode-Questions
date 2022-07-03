class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        //boundary case
        int row=grid.size();
        int col=grid[0].size();
        
        //boundary case
        if(i<0 || i>=row || j<0 || j>=col)
        {
            return 1e8;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(i==row-1 and j==col-1)
        {
            //we reach the end 
            return grid[i][j];
        }
        int a=grid[i][j]+solve(i+1,j,grid,dp);
        int b=grid[i][j]+solve(i,j+1,grid,dp);
        
        return dp[i][j]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        int i=0;
        int j=0;
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(i,j,grid,dp);
    }
};