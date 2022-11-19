class Solution {
public:
    int solve(int idx,vector<int>&coins,int sum,vector<vector<int>>&dp)
    {
        //base case
        if(idx==coins.size())
        {
            return 1e9;//since we need the minimum as the answer
            
        }
        if(sum==0)
        {
            return 1;//we able to make the bound
        }
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        
        if(coins[idx]<=sum)
        {
            //two choice will choose it or not choose it
            return dp[idx][sum]=min(1+solve(idx,coins,sum-coins[idx],dp),solve(idx+1,coins,sum,dp));
        }
        else
        {
            return dp[idx][sum]=solve(idx+1,coins,sum,dp);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        int sum=amount;
        
        int idx=0;
        
        //if it retrun the large value or infite value then its not possible to make the amount with the given coins
        //two things are changing index and sum
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        if(solve(idx,coins,sum,dp)>=1e9)
        {
            return -1;
        }
        else
        {
            return solve(idx,coins,sum,dp)-1;
        }
    }
};