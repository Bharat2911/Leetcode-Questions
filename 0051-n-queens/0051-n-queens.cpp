class Solution {
public:
    void solve(int col,int n,vector<vector<string>>&ans,vector<string>&res,vector<int>&right,vector<int>&left_right,vector<int>&left_down)
    {
        if(col==n)
        {
            ans.push_back(res);
            
            return;
        }
        //now i have to loop  over any try to put queen in 1st column 
        for(int row=0;row<n;row++)
        {
            //if my positions are not visited then only i will be putting q there 
            if(right[row]==0 and left_down[row+col]==0 and left_right[n-1+col-row]==0)
            {
                //put the answer make them visited recursie call then make then unvisited
                res[row][col]='Q';
                right[row]=1;
                left_down[row+col]=1;
                left_right[n-1+col-row]=1;
                
                solve(col+1,n,ans,res,right,left_right,left_down);
                
                //unvisited it that is backtracking step
                
                res[row][col]='.';
                right[row]=0;
                left_down[row+col]=0;
                left_right[n-1+col-row]=0;
                
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        
        vector<string>res(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            res[i]=s;
        }
        
        vector<int>right(n,0);
        vector<int>left_upper(2*n-1,0);
        vector<int>left_down(2*n-1,0);
        
        int col=0;
        
        solve(col,n,ans,res,right,left_upper,left_down);
        
        return ans;
    }
};