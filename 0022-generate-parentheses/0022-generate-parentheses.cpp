class Solution {
public:
    void solve(int open,int close,int n,string str,vector<string>&ans)
    {
        if(str.length()==2*n)
        {
            ans.push_back(str);
            return;
        }
        
        if(open<n)
        {
            solve(open+1,close,n,str+"(",ans);
        }
         if(close<open)
        {
            solve(open,close+1,n,str+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        string str="(";
        
        int open=1;
        int close=0;
        
        vector<string>ans;
        
        solve(open,close,n,str,ans);
        
        
        return ans;
    }
};