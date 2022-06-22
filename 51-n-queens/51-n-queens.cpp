class Solution {
public:
    //making the recursive function
    void solve(int col,int n, vector<vector<string>>&ans, vector<string>&board,vector<int>&left_row, vector<int>&upper_diag,vector<int>&lower_diag)
    {
        //base case
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(left_row[row]==0 and lower_diag[row+col]==0 and upper_diag[n+col-row-1]==0)
            {
                board[row][col]='Q';
                
                left_row[row]=1;
                lower_diag[row+col]=1;
                upper_diag[n+col-row-1]=1;
                
                //recursive call
                
                solve(col+1,n,ans,board,left_row,upper_diag,lower_diag);
                
                //backtraking step;
                board[row][col]='.';
                
                left_row[row]=0;
                lower_diag[row+col]=0;
                upper_diag[n+col-row-1]=0;
                
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        vector<string>board(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
            
        }
        // /one q can onlybe killed from th ebackward 
        vector<int>left_row(n,0);
        vector<int>upper_diag(2*n-1,0);
        vector<int>lower_diag(2*n-1,0);
        
        int index=0;//or the starting col
        
        solve(index,n,ans,board,left_row,upper_diag,lower_diag);
        
        return ans;
        
        
    }
};