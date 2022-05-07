class Solution {
public:
    //dfs is a type of recursice sol so memonize it using dp
    
    int dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int row=matrix.size();
        int col=matrix[0].size();
        if(dp[i][j]!=-1)return dp[i][j];
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        int res=1;
        
        for(int idx=0;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            
            if(newi>=0 and newi<row and newj>=0 and newj<col and matrix[i][j]<matrix[newi][newj])
            {
                res=max(res,1+dfs(newi,newj,matrix,dp));
            }
        }
        return dp[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        //we  will be solving this using the dfs
        //dfs is just like recursion 
        //if tle then memonize it using the dp
        
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        
        int ans=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
        
    }
};