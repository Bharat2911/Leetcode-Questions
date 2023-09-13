class Solution {
public:
    int solve(int i,int j,string&s,string&t,vector<vector<int>>&dp)
    {
        if(j<0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
            
        }
        if(s[i]==t[j])
        {
            return dp[i][j]=solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
        }
        else
        {
            return dp[i][j]=solve(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        
        //base case hoga jab t mera exausted kar jye
        
        int n=s.length();
        int m=t.length();
        
        int i=n-1;
        int j=m-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return solve(i,j,s,t,dp);
    }
};