class Solution {
public:
    int dp[1001][1001];
    
    int solve(string&s ,string&t,int i,int j)
    {
        if(j<0)return 1;
        
        if(i<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==t[j])
        {
            return dp[i][j]=solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
        }
        else
        {
            return dp[i][j]=solve(s,t,i-1,j);
        }
    }
    int numDistinct(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        int i=n-1;
        int j=m-1;
        
        memset(dp,-1,sizeof dp);
        
        return solve(s,t,i,j);
    }
};