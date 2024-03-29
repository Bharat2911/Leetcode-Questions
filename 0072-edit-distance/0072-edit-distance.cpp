class Solution {
public:
    int solve(int i,int j,string&s1,string&s2,vector<vector<int>>&dp)
    {
        if(i==-1)
        {
            return j+1;
        }
        if(j==-1)
        {
            return i+1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(s1[i]==s2[j])
        {
            return dp[i][j]=solve(i-1,j-1,s1,s2,dp);//isme count nahi karenge kyuki isme koi operations use nahi ho rhe boss
        }
        
        /// we have to give the minimum operations so operations jab use hoga tab hi to usko count karenge na dost
        
        int a=1+solve(i-1,j,s1,s2,dp);
        
        int b=1+solve(i,j-1,s1,s2,dp);
        
        int c=1+solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=min({a,b,c});
    }
    int minDistance(string s1, string s2) {
        
        int n=s1.length();
        
        int m=s2.length();
        
        int i=n-1;
        int j=m-1;
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solve(i,j,s1,s2,dp);
    }
};