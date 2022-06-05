class Solution {
public:
      void solve(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&left_row,vector<int>&upper_diag,vector<int>&lower_diag,int n)
    {
        //base case
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(left_row[row]==0 and lower_diag[row+col]==0 and upper_diag[n-1+col-row]==0)
            {
                board[row][col]='Q';
                
                left_row[row]=1;
                lower_diag[row+col]=1;
                upper_diag[n-1+col-row]=1;
                
                solve(col+1,ans,board,left_row,upper_diag,lower_diag,n);
                
                //backtrakingstep
                board[row][col]='.';
                
                 left_row[row]=0;
                lower_diag[row+col]=0;
                upper_diag[n-1+col-row]=0;
                
            }
        }
    }
    int totalNQueens(int n) {
         vector<vector<string>>ans;
        vector<string>board(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
            
        }
        
        vector<int>left_row(n,0);
        vector<int>upper_diag(2*n-1,0);
        vector<int>lower_diag(2*n-1,0);
        
        solve(0,ans,board,left_row,upper_diag,lower_diag,n);
        
        return ans.size();
    }
};