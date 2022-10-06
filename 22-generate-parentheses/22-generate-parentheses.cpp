class Solution {
public:
    void solve(vector<string>&ans,int n,string str,int open,int close)
    {
        if(str.length()==2*n)
        {
            ans.push_back(str);
            return;
        }
        
        if(open<n)
        {
            solve(ans,n,str+"(",open+1,close);
        }
        if(close<open)
        {
            solve(ans,n,str+")",open,close+1);
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        
        int open=1;
        int close=0;
        
        string str="(";
        
        vector<string>ans;
        
        solve(ans,n,str,open,close);
        
        return ans;
    }
};