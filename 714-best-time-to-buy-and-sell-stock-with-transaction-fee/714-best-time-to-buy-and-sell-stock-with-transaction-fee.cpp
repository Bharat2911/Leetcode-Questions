class Solution {
public:
      
    int f(int idx,bool isbuy,vector<int>&prices,int n,vector<vector<int>>&dp,int fee)
    {
        //base case
        if(idx==n)
        {
            return 0;
        }
        
        int profit=0;
        
        if(dp[idx][isbuy]!=-1)return dp[idx][isbuy];
        
        //choice diagram
        if(isbuy)
        {
            //take or not take two choices here
            profit=max(-prices[idx]+f(idx+1,false,prices,n,dp,fee)  , 0+f(idx+1,true,prices,n,dp,fee));
        }
        else
        {
            //whter to sell or not sell again two choices here
            profit=max(prices[idx]-fee+f(idx+1,true,prices,n,dp,fee)  , 0+f(idx+1,false,prices,n,dp,fee)); 
        }
        
        return dp[idx][isbuy]=profit;
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        
         int n=prices.size();
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        
        return f(0,true,prices,prices.size(),dp,fee);
    }
};