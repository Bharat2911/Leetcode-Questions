class Solution {
public:
    int solve(int i,int j,int row,int col,vector<vector<int>>&dp)
    {
        if(i<0 || i>=row || j<0 || j>=col)
        {
            return 0;
        }
        
        if(i==row-1 and j==col-1)
        {
            return 1;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=solve(i+1,j,row,col,dp);
        
        int b=solve(i,j+1,row,col,dp);
        
        return dp[i][j]=a+b;
    }
    int uniquePaths(int m, int n) {
        
        int row=m;
        int col=n;
        
        vector<vector<int>>dp(row,vector<int>(col,-1));
        
        return solve(0,0,m,n,dp);
    }
};