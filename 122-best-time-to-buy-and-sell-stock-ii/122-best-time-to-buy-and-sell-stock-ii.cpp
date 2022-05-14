class Solution
{
    public:
        int solve(int idx, int n, vector<int> &prices, bool isbuy,vector<vector<int>>&dp)
        {
           	//base case
            if (idx == n)
            {
                return 0;
            }
            
            if(dp[idx][isbuy]!=-1)
            {
                return dp[idx][isbuy];
            }
           	//choice didagram

           	//if buy allowed 
           	// -> buy
           	// ->not buy

           	//if sell allowed
           	// ->sell
           	// ->not sell
            int profit = 0;

            if (isbuy)
            {
                profit = max(-prices[idx] + solve(idx + 1, n, prices, false,dp), 0 + solve(idx + 1, n, prices, true,dp));
            }
            else
            {
               	//sell is alowed
                profit = max(prices[idx] + solve(idx + 1, n, prices, true,dp), 0 + solve(idx + 1, n, prices, false,dp));
            }

            return dp[idx][isbuy]=profit;
        }
    int maxProfit(vector<int> &prices)
    {

        int idx = 0;
        int n = prices.size();
        bool isbuy = true;
        vector<vector < int>> dp(n, vector<int> (2, -1));
        return solve(idx, n, prices, isbuy,dp);
    }
};