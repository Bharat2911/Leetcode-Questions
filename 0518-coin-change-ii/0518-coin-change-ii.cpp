class Solution {
public:
    int solve(int idx,vector<int>&coins,int sum,vector<vector<int>>&dp)
    {
        //base case
        int n=coins.size();
        
        if(idx==n)
        {
            return 0;
        }
        
        if(sum==0)
        {
            return 1;
        }
        if(sum<0)
        {
            return 0;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        if(coins[idx]<=sum)
        {
            return dp[idx][sum]=(solve(idx,coins,sum-coins[idx],dp)+solve(idx+1,coins,sum,dp));
        }
        else
        {
            return dp[idx][sum]=solve(idx+1,coins,sum,dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        
         int n=coins.size();
        
        int sum=amount;
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        
        
        return solve(0,coins,amount,dp);
    }
};