class Solution {
public:
    //using recursion +memonization (itn short using the dp)
    
    int solve(int m,int n,vector<vector<int>>&dp)
    {
        //base case
        if(m==0 || n==0)return 0;
        
        if(m==1 || n==1)return 1;
        
        if(dp[m][n]!=-1)return dp[m][n];
        
        
        int a=solve(m-1,n,dp);
        int b=solve(m,n-1,dp);
        
        return dp[m][n]=a+b;
        
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return solve(m,n,dp);
        
    }
};