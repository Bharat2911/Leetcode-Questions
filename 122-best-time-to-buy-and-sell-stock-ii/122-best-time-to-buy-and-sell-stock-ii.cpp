class Solution {
public:
    int solve(int idx,vector<int>&prices,bool is_buy,vector<vector<int>>&dp)
    {
        //base case
        if(idx==prices.size())
        {
            return 0;
        }
        
        int profit=0;
        
        if(dp[idx][is_buy]!=-1)return dp[idx][is_buy];
        
        if(is_buy==true)
        {
            profit=max(-prices[idx]+solve(idx+1,prices,false,dp),solve(idx+1,prices,true,dp));
        }
        
        else
        {
            profit=max(prices[idx]+solve(idx+1,prices,true,dp),solve(idx+1,prices,false,dp));
        }
        return dp[idx][is_buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        //we will be doing this using recursion bitch
        int n=prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        
        int idx=0;
        
        bool is_buy=true;
        
        return solve(idx,prices,is_buy,dp);
        
        
    }
};