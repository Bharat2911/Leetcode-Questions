class Solution {
public:
    int dp[55][55][55];
    long long mod=1e9+7;
    
    int solve(int i,int j,int row,int col,int moves)
    {
        //base case
        //when ever goes out of boundary rteutn 1
        if(i<0 || i>=row || j<0 || j>=col)
        {
            return 1;
        }
        
        //if moves exausted 
        if(moves<=0)
        {
            return 0;
        }
        if(dp[i][j][moves]!=-1)return dp[i][j][moves];
        
        
        //choice diagram 
        //we have four choices and sum of all four will give our answer
        int a=solve(i+1,j,row,col,moves-1);
         int b=solve(i-1,j,row,col,moves-1);
         int c=solve(i,j+1,row,col,moves-1);
         int d=solve(i,j-1,row,col,moves-1);
        
        return dp[i][j][moves]=(a%mod+b%mod+c%mod+d%mod)%mod;
    }
    int findPaths(int row, int col, int moves, int i, int j) {
        
        //we will simply write the recursion for it and memonized it later
        
        memset(dp,-1,sizeof dp);
        
        return solve(i,j,row,col,moves);
    }
    //in each itration three things changes (row,col,moves);
    //T.C =O(n*m*moves);
    //S.C =o(n*m*moves);
    
};