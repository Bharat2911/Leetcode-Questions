class Solution {
public:
   int f(int idx, bool isbuy, vector<int> &prices, int n, vector<vector< vector< int>>> &dp, int k)
        {
           	//base case
            if (idx == n || k == 0)
            {
                return 0;
            }

            int profit = 0;

            if (dp[idx][isbuy][k] != -1) return dp[idx][isbuy][k];

           	//choice diagram
            if (isbuy)
            {
               	//take or not take two choices here
                profit = max(-prices[idx] + f(idx + 1, false, prices, n, dp, k), 0 + f(idx + 1, true, prices, n, dp, k));
            }
            else
            {
               	//whter to sell or not sell again two choices here
                profit = max(prices[idx] + f(idx + 1, true, prices, n, dp, k - 1), 0 + f(idx + 1, false, prices, n, dp, k));
            }

            return dp[idx][isbuy][k] = profit;
        }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<vector< int>>> dp(n, vector<vector < int>> (2, vector<int> (3, -1)));

        return f(0, true, prices, prices.size(), dp, 2);
    }
};