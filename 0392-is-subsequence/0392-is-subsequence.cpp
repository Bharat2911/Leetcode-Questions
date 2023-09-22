class Solution {
public:
    void solve(int i,int j,string&s,string&t,bool &ans)
    {
        if(i<0)
        {
            ans=true;
            
            return;
            
        }
        if(j<0 )return ;
        
        if(s[i]==t[j])
        {
            solve(i-1,j-1,s,t,ans);
        }
        else
        {
            solve(i,j-1,s,t,ans);
        }
    }
    bool isSubsequence(string s, string t) {
        
        int n=s.length();
        
        int m=t.length();
        
        int i=n-1;
        
        int j=m-1;
        
        bool ans=false;
        
         solve(i,j,s,t,ans);
        
        return ans;
    }
};