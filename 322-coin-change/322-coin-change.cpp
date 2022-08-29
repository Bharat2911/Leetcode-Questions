class Solution {
public:
    
    int solve(int idx,vector<int>&coins,int sum,int n,vector<vector<int>>&dp)
    {
        if(idx==n)
        {
            return 1e9;
        }
        
        if(sum==0)
        {
            return 1;
        }
        
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        
        if(coins[idx]<=sum)
        {
            return dp[idx][sum]=min(1+solve(idx,coins,sum-coins[idx],n,dp),solve(idx+1,coins,sum,n,dp));
        }
        else
        {
            return dp[idx][sum]=solve(idx+1,coins,sum,n,dp);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        int sum=amount;
        
        int idx=0;
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        if(solve(idx,coins,sum,n,dp)>=1e9)
        {
            return -1;
        }
        
        else return solve(idx,coins,sum,n,dp)-1;
        
    }
};