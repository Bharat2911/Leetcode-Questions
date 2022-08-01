class Solution {
public:
    int solve(int i,int j,int row ,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i<0 || i>=row  || j<0 || j>=col)
        {
            return 0;
        }
        
        if(grid[i][j]==1)
        {
            return 0;
        }
        
        if(i==row-1 and j==col-1)
        {
            return 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
            
        }
        
        int down=solve(i+1,j,row,col,grid,dp);
        
        int right=solve(i,j+1,row,col,grid,dp);
        
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        int i=0;
        int j=0;
        
        vector<vector<int>>dp(row,vector<int>(col,-1));
        
        
        return solve(i,j,row,col,grid,dp);
        
    }
};