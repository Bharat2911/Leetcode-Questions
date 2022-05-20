class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        int row=grid.size();
        int col=grid[0].size();
        
        //basec conditions
         if(  i>=row ||   j>=col)return 0;
        
        if(grid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        if(i==row-1 and j==col-1)return 1;
        
        int a=solve(i+1,j,grid,dp);
        int b=solve(i,j+1,grid,dp);
        
        return dp[i][j]=a+b;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        //use the recursion simple
        //try all possible path
        
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        
        int starti=0;
        int startj=0;
        
        return solve(starti,startj,grid,dp);
        
    }
};