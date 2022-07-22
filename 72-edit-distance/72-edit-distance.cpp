class Solution
{
    public:
        int solve(string &s1, string &s2, int i, int j,vector<vector<int>>&dp)
        {
           	//we will convert s1 to s2 and we have given three operations
            if (j < 0) return i+1;
            if(i<0)return j+1;
            
            if(dp[i][j]!=-1)return dp[i][j];
            
            int a=0;
            int b=0;
            int c=0;
            
            if (s1[i] == s2[j])//no operation is used in this
            {
                return solve(s1,s2,i-1,j-1,dp);
            }
            
            else
            {
                //three operationns we will be using here
                
                a=1+solve(s1,s2,i-1,j,dp);
                b=1+solve(s1,s2,i,j-1,dp);
                c=1+solve(s1,s2,i-1,j-1,dp);
                
            }
            return dp[i][j]=min({a,b,c});
        }
    int minDistance(string word1, string word2)
    {

        int n = word1.length();
        int m = word2.length();
        int i = n - 1;
        int j = m - 1;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solve(word1, word2, i, j,dp);
    }
};