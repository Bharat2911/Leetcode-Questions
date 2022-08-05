class Solution {
public:
  
    int solve(int idx,int n,vector<int>&coins,int sum,vector<vector<int>>&dp)
    {
        if(idx==n)return 1e9;
        
        if(sum==0)return 1;
        
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        
        if(coins[idx]<=sum)
        {
            return dp[idx][sum]=min(1+solve(idx,n,coins,sum-coins[idx],dp),solve(idx+1,n,coins,sum,dp));
        }
        else
        {
            return dp[idx][sum]=solve(idx+1,n,coins,sum,dp);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        int sum=amount;
        
        int idx=0;
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return solve(idx,n,coins,sum,dp)>=1e9?-1:solve(idx,n,coins,sum,dp)-1;
    }
};