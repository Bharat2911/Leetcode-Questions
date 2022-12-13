class Solution {
public:
    
    int dp[101][101];
    
    int solve(int i,int j,int row,int col,vector<vector<int>>&grid)
    {
        //base case out of bound
        if(j<0 || j>=col)
        {
            //since we need minimum so we will return an maximum value
            return 1e9+7;
        }
        
        if(i==row)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a=grid[i][j]+solve(i+1,j-1,row,col,grid);
        int b=grid[i][j]+solve(i+1,j,row,col,grid);
        int c=grid[i][j]+solve(i+1,j+1,row,col,grid);
        
        return dp[i][j]=min({a,b,c});
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        
        int col=matrix[0].size();
        
        int ans=INT_MAX;
        
        memset(dp,-1,sizeof dp);
        
        for(int j=0;j<col;j++)
        {
           ans=min(ans,solve(0,j,row,col,matrix)) ;
        }
        
        
        return ans;
    }
};