class Solution {
public:
    int dp[301];
    
    bool solve(int idx,string&s,vector<string>&wd,int n)
    {
        if(idx==n)
        {
            return true;
        }
        
        if(dp[idx]!=-1)return dp[idx];
        
        for(auto itr:wd)
        {
            int l=itr.length();
            
            string str=s.substr(idx,l);
            
            if(str==itr)
            {
                if(solve(idx+l,s,wd,n))return dp[idx]=true;
            }
            
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        
        int n=s.length();
        
        int idx=0;
        
        memset(dp,-1,sizeof dp);
        
        
        return solve(idx,s,wd,n);
    }
};