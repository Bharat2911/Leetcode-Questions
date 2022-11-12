class Solution {
public:
    //recursion solution
    int dp[46];
    
    int solve(int n)
    {
        //base case
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return 1;
        }
        
        if(dp[n]!=-1)return dp[n];
        
        //cjpice diagram
        int a=solve(n-1);
        
        int b=solve(n-2);
        
        return dp[n]=a+b;
    }
    int climbStairs(int n) {
        
        memset(dp,-1,sizeof dp);
        
        return solve(n);
    }
};