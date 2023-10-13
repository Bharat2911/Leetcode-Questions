class Solution {
public:
    bool solve(int i,int j,string&s,string&t)
    {
        if(i<0)return true;
        
        if(j<0)return false;
        
        
        if(s[i]==t[j])
        {
            return solve(i-1,j-1,s,t);
        }
        else
        {
            return solve(i,j-1,s,t);
        }
    }
    bool isSubsequence(string s, string t) {
        
       int n=s.length();
        
       int m=t.length();
        
        int i=n-1;
        
        int j=m-1;
        
        return solve(i,j,s,t);
    }
};