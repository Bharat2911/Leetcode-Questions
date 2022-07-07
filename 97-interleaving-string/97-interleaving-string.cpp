class Solution
{
    public:
        int dp[101][101];
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
    {

        if (i + j != k) return false;

        if (k == 0)
        {
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        bool x = false;
        bool y = false;

        if (i - 1 >= 0 and s1[i - 1] == s3[k - 1])
        {
            x = solve(s1, s2, s3, i - 1, j, k - 1);
        }
        if (j - 1 >= 0 and s2[j - 1] == s3[k - 1])
        {
            y = solve(s1, s2, s3, i, j - 1, k - 1);
        }

        return dp[i][j] = x || y;
    }
    bool isInterleave(string s1, string s2, string s3)
    {

        int i = s1.length();
        int j = s2.length();
        int k = s3.length();
        memset(dp, -1, sizeof dp);
        return solve(s1, s2, s3, i, j, k);
    }
};