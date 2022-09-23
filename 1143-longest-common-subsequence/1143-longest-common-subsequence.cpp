class Solution
{
    public:
        int solve(int i, int j, string &s1, string &s2,vector<vector<int>>&dp)
        {
            int n = s1.length();
            int m = s2.length();

           
            if (j == m || i == n) return 0;
            
            if(dp[i][j]!=-1)return dp[i][j];
            
            if (s1[i] == s2[j])
            {
                return dp[i][j]=1 + solve(i + 1, j + 1, s1, s2,dp);
            }
            else
            {
                return dp[i][j]=max(solve(i + 1, j, s1, s2,dp), solve(i, j + 1, s1, s2,dp));
            }
        }
    int longestCommonSubsequence(string text1, string text2)
    {

        int i = 0;
        int j = 0;
        
        int n=text1.length();
        int m=text2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        

        return solve(i, j, text1, text2,dp);
    }
};