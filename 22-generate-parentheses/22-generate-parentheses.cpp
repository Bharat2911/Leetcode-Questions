class Solution
{
    public:
    void solve(string output,int open,int close,vector<string>&ans,int n)
    {
        //base case
        if(output.length()==2*n)
        {
            ans.push_back(output);
            return;
        }
        
        //two conditions we have
        if(open<n)
        {
            solve(output+"(",open+1,close,ans,n);
        }
        
        if(close<open)
        {
            solve(output+")",open,close+1,ans,n);
        }
        
        //backtracking step
        output.pop_back();
    }
        vector<string> generateParenthesis(int n)
        {

            vector<string> ans;

            solve("(", 1, 0, ans, n);

            return ans;
        }
};