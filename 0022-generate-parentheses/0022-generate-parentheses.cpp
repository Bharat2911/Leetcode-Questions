class Solution {
public:
    void solve(int n,string res,vector<string>&ans,int open,int close)
    {
        //base case
        if(res.length()==2*n)
        {
            ans.push_back(res);
            return;
        }
        
        if(open<n)
        {
            //then i can add open
            solve(n,res+"(",ans,open+1,close);
        }
        if(close<open)
        {
            //adding the close  bracket
            
            solve(n,res+")",ans,open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        
        int open=1;
        int close=0;
        
        string res="(";
        
        vector<string>ans;
        
        solve(n,res,ans,open,close);
        
        return ans;
    }
};