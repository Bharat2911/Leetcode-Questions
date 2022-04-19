class Solution {
public:
    int solve(int i,int j,int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        //base cases
        if(i>=row || j>=col )return 0;//out of condition
        
        if(grid[i][j]==1)return 0;//we get the obstackel;
        
        if(i==row-1 and j==col-1)return 1;//means we reach the end
        
        if(dp[i][j]!=-1)return dp[i][j];//dp base case
        
        
        int a=solve(i+1,j,row,col,grid,dp);
        int b=solve(i,j+1,row,col,grid,dp);
        
        return dp[i][j]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        //same as unique path 1 just a little change
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        
        return solve(0,0,row,col,grid,dp);
    }
};