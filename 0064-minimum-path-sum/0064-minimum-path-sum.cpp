class Solution {
public:
     int dp[201][201];
    
    int solve(int i,int j,int row,int col,vector<vector<int>>&grid)
    {
        if(i<0 || i>=row || j<0 || j>=col)
        {
            return 1e9+7;
        }
        if(i==row-1 and j==col-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int down=grid[i][j]+solve(i+1,j,row,col,grid);
        int right=grid[i][j]+solve(i,j+1,row,col,grid);
        
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        memset(dp,-1,sizeof dp);
        
        return solve(0,0,row,col,grid);
    }
};