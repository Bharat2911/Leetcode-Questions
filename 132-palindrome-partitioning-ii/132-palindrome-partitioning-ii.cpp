class Solution {
public:
    //only i and j are changes
    int dp[2001][2001];
    
    bool ispal(string&s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }
    int solve(string&s,int i,int j)
    {
        //base case
        if(i>=j)
        {
            return 0;
        }
        
        if(ispal(s,i,j))return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            if(ispal(s,i,k))
            {
                int temp=solve(s,i,k)+solve(s,k+1,j)+1;
                
                ans=min(ans,temp);
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        
        int n=s.length();
        
        int i=0;
        int j=n-1;
        memset(dp,-1,sizeof(dp));
        
        return solve(s,i,j);
    }
};