class Solution {
public:
    int solve(int i,int j,int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        //base case
        if(i<0 || j<0 || i>=row || j>=col)
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
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=solve(i+1,j,row,col,grid,dp);
        
        int b=solve(i,j+1,row,col,grid,dp);
        
        return dp[i][j]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        
        int i=0;
        int j=0;
        
        return solve(i,j,row,col,grid,dp);
        
        
    }
};