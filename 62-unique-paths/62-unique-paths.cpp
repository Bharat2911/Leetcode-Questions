class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        //base case
        //outof bound condtiion
        
        if(i<0 || i>=m || j<0 ||j>=n)
        {
            return 0;
        }
        
        if(i==m-1 and j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=solve(i+1,j,m,n,dp);
        int b=solve(i,j+1,m,n,dp);
        
        return dp[i][j]=a+b;
    }
    int uniquePaths(int m, int n) {
        
        int i=0;
        int j=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(i,j,m,n,dp);
        
        
    }
};