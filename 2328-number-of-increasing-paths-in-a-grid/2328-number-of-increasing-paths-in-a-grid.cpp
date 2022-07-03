class Solution {
public:
    long long mod=1e9+7;
    
    int solve(int i,int j,int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        int ans=1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        for(int idx=0 ;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            if(newi>=0 and newi<row and newj>=0 and newj<col and grid[newi][newj]>grid[i][j])
            {
                ans=ans%mod+solve(newi,newj,row,col,grid,dp)%mod;
            }
        }
        return dp[i][j]=ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        
        //this is same as ongest inc path there we do max here do just add
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>>dp(row,vector<int>(col,-1));
        
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans=ans%mod+solve(i,j,row,col,grid,dp)%mod;
            }
        }
        return ans%mod;
    }
};