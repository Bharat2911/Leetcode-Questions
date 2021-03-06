class Solution
{
    public:
    // ans will be 
    //length of string 1+length of string 2+2*(lcs)
    
        int minDistance(string word1, string word2)
        {

           	//base case
            if (word1 == word2)
            {
                return 0;
            }

            int n = word1.length();
            int m = word2.length();

           
            int dp[n + 1][m + 1];

            for (int i = 0; i < n + 1; i++)
            {
                for (int j = 0; j < m + 1; j++)
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 0;
                    }
                }
            }

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < m + 1; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            // return dp[n][m];
            return n+m-2*(dp[n][m]);
        }
};