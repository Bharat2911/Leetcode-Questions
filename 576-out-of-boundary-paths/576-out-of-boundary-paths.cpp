class Solution {
public:
    int dp[55][55][55];
    long long mod = 1e9 + 7;
    int solve(int i,int j,int row,int col,int moves)
    {
        //base case
        
        if(i<0 |i>=row || j<0 || j>=col)return 1;
        
        if(dp[i][j][moves]!=-1)return dp[i][j][moves];
        
        if(moves<=0)return 0;
        
        int a=solve(i+1,j,row,col,moves-1);
        int b=solve(i-1,j,row,col,moves-1);
        int c=solve(i,j+1,row,col,moves-1);
        int d=solve(i,j-1,row,col,moves-1);
        
        return dp[i][j][moves]=(a%mod+b%mod+c%mod+d%mod)%mod;
        
        
    }
    int findPaths(int row, int col, int moves, int i, int j) {
        
        //will make a dp since three things are chanig row col and moves
        memset(dp,-1,sizeof dp);
        
        return solve(i,j,row,col,moves);
    }
};