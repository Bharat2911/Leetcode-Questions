class Solution {
public:
    //theen cheeze change ho rhi hai
    //idx ,m ,n 
    int dp[601][101][101];
    
    int solve(vector<string>&str,int m,int n,int idx)
    {
        if(idx==str.size()  )return 0;
        if(m==0 and n==0)return 0;
        
        if(dp[idx][m][n]!=-1)return dp[idx][m][n];
        
        int zero=0;
        int one=0;
        
        for(int j=0;j<str[idx].length();j++)
        {
            if(str[idx][j]=='0')zero++;
            else one++;
        }
        
        int ans=0;
        
        if(zero<=m and one<=n)
        {
            ans=max(solve(str,m-zero,n-one,idx+1)+1,solve(str,m,n,idx+1));
        }
        else
        {
            ans=solve(str,m,n,idx+1);
        }
        return dp[idx][m][n]=ans;
    }
    int findMaxForm(vector<string>& str, int m, int n) {
        
        int sz=str.size();
        
        int idx=0;
        
        memset(dp,-1,sizeof(dp));      
        
        return solve(str,m,n,idx);
    }
};