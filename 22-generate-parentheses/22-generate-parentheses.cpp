class Solution {
public:
    
    void solve(string pattern,int open,int close,int n,vector<string>&ans)
    {
        if(pattern.length()==2*n)
        {
            ans.push_back(pattern);
            return;
        }
        
        //two choices
        if(open<n)
        {
            solve(pattern+"(",open+1,close,n,ans);
        }
        if(close<open)
        {
            solve(pattern+")",open,close+1,n,ans);
        }
        // pattern.pop_back();//backtraking step;
    }
    vector<string> generateParenthesis(int n) {
        
        int open=1;
        int close=0;
        
        vector<string>ans;
        
        
        
        solve("(",open,close,n,ans);
        
        return ans;
    }
};