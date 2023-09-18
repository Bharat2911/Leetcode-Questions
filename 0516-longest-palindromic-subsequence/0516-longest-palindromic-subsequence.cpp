class Solution {
    
public:
    
    int dp[1001][1001];
    
    int solve(int i,int j,string&s,string&t)
    {
        //base case
        
        if(i<0 || j<0)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(s[i]==t[j])
        {
            return dp[i][j]=1+solve(i-1,j-1,s,t);
        }
        
        else
        {
            return dp[i][j]=max(solve(i-1,j,s,t),solve(i,j-1,s,t));
        }
    }
    int longestPalindromeSubseq(string s) {
        
        //simple trick 
        //make another string which is reverse of the output of given string
        //now simply find the lcs of both string
        //this will give lps
        
        string t=s;
        
        memset(dp,-1,sizeof dp);
        
        reverse(t.begin(),t.end());
        
        int n=s.length();
        
        int i=n-1;
        
        int j=n-1;
        
        return solve(i,j,s,t);
    }
};