class Solution {
public:
    int dp[1001][101][2];
    
    int solve(int idx,vector<int>&prices,int k,bool isbuy)
    {
        //bsae case
        int n=prices.size();
        
        if(idx==n)
        {
            return 0;
        }
        if(k==0)
        {
            return 0;
        }
        
        if(dp[idx][k][isbuy]!=-1)return dp[idx][k][isbuy];
        
        int profit=0;
        
        if(isbuy==true)
        {
            //will buy  or // not buy
            profit=max(-prices[idx]+solve(idx+1,prices,k,false),solve(idx+1,prices,k,true));
        }
        else
        {
            profit=max(prices[idx]+solve(idx+1,prices,k-1,true),solve(idx+1,prices,k,false));
        }
        
        return dp[idx][k][isbuy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        
        int idx=0;
        
        bool isbuy=true;
        
        memset(dp,-1,sizeof dp);
        
        return solve(idx,prices,k,isbuy);
    }
};