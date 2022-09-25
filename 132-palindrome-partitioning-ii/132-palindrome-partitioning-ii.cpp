class Solution
{
    public:
        
        int dp[2001][2001];
    
        bool ispal(string &str, int low, int high)
        {
            while (low <= high)
            {
                if (str[low++] != str[high--])
                {
                    return false;
                }
            }
            return true;
        }
    int solve(int i, int j, string &str)
    {
       	//base case
        if (i > j) return 0;

        if (ispal(str, i, j))	//if given string is already palindrome
        {
            return 0;
        }
        int ans = INT_MAX;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        for (int k = i; k < j; k++)
        {
            if (ispal(str, i, k))
            {
                int x = 1 + solve(i, k, str) + solve(k + 1, j, str);

                ans = min(ans, x);
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string str)
    {

        int n = str.length();

        int i = 0;
        
        int j = n - 1;
        
        memset(dp,-1,sizeof dp);
        
        return solve(i, j, str);
    }
};