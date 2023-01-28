class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&mat,int row,int col,vector<vector<int>>&dp)
    {
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        int ans=1;
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        for(int idx=0;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            
            if(newi>=0 and newi<row and newj>=0 and newj<col and mat[newi][newj]>mat[i][j] )
               {
                   int count=1+solve(newi,newj,mat,row,col,dp);
                   ans=max(ans,count);
               }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        
        int col=matrix[0].size();
        
        vector<vector<int>>dp(row,vector<int>(col,-1));
        
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans=max(ans,solve(i,j,matrix,row,col,dp));
            }
        }
        return ans;
    }
};