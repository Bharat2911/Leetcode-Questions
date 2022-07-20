class Solution {
public:
    bool isSubsequence(string s, string t) {
        
      //find thelength of longest common subsequence 
        int n=s.length();
        int l=t.length();
        int dp[n+1][l+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<l+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<l+1;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int len=dp[n][l];
        
        if(s.length()==len)return true;
        return false;
        
    }
};